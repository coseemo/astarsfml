#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "astar.h"

using namespace std;

// Costruttore della classe MapSearchNode, inizializzo il nodo con le coordinate e la mappa
MapSearchNode::MapSearchNode(int x, int y, Map* map) : x(x), y(y), map(map) {}

// Verifico se lo stato corrente è lo stesso di un altro nodo (stessa posizione)
bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{
    // Lo stato è uguale se le coordinate (x, y) sono le stesse
    if( (x == rhs.x) && (y == rhs.y) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Stampo le informazioni sul nodo corrente (le sue coordinate)
void MapSearchNode::PrintNodeInfo()
{
    const int strSize = 100;
    char str[strSize];
    snprintf( str, strSize, "Node position : (%d,%d)\n", y, x );

    cout << str;
}

// Funzione euristica che stima la distanza tra il nodo corrente e il nodo obiettivo
float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    // Utilizzo la distanza di Manhattan come euristica
    return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

// Verifico se il nodo corrente è il nodo obiettivo
bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{
    // Il nodo è l'obiettivo se le coordinate coincidono
    if( (x == nodeGoal.x) && (y == nodeGoal.y) )
    {
        return true;
    }

    return false;
}

// Genero i successori del nodo corrente (i nodi adiacenti) senza tornare indietro
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{
    // Inizializzo le coordinate del nodo genitore
    int parent_x = -1;
    int parent_y = -1;

    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }

    MapSearchNode NewNode;

    // Aggiungo i successori senza consentire di tornare indietro
    if( (map->getMap( x-1, y ) < 9)
        && !((parent_x == x-1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x-1, y, map);
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->getMap( x, y-1 ) < 9)
        && !((parent_x == x) && (parent_y == y-1))
            )
    {
        NewNode = MapSearchNode( x, y-1 , map);
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->getMap( x+1, y ) < 9)
        && !((parent_x == x+1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x+1, y, map);
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->getMap( x, y+1 ) < 9)
        && !((parent_x == x) && (parent_y == y+1))
            )
    {
        NewNode = MapSearchNode( x, y+1, map);
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

// Calcolo il costo per muoversi da questo nodo al nodo successore
float MapSearchNode::GetCost( MapSearchNode &successor )
{
    // Il costo è il valore del terreno alla posizione corrente
    return (float) map->getMap( x, y );
}

// Funzione che restituisce l'hash del nodo basato sulle coordinate
size_t MapSearchNode::Hash()
{
    size_t h1 = hash<float>{}(x);
    size_t h2 = hash<float>{}(y);
    return h1 ^ (h2 << 1);
}

// Funzione principale per l'algoritmo A*
vector<Tile*> astar(Tile &start, Tile &end, Map &map) {

    // Verifico che la posizione di partenza o di arrivo non siano bloccate
    if (start.getCost() == 9 || end.getCost() == 9) {
        cout << "non trovato\n";
        return {};
    }

    // Inizializzo la ricerca A*
    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;

    vector<Tile*> path;

    // Ciclo di ricerca
    while(SearchCount < NumSearches)
    {
        // Definisco il nodo di partenza e di arrivo
        MapSearchNode nodeStart(start.getX(), start.getY(), &map);
        MapSearchNode nodeEnd(end.getX(), end.getY(), &map);

        // Imposto lo stato di partenza e l'obiettivo
        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {
            // Eseguo un passo della ricerca A*
            SearchState = astarsearch.SearchStep();
            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

			int len = 0;

			// Stampo i nodi nella lista aperta
			cout << "Open:\n";
			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();
			}

			cout << "Open list has " << len << " nodes\n";

			len = 0;

			// Stampo i nodi nella lista chiusa
			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				p->PrintNodeInfo();
	#endif
				p = astarsearch.GetClosedListNext();
			}

			cout << "Closed list has " << len << " nodes\n";
#endif

        }
            // Continuo a cercare finché non trovo il nodo obiettivo o fallisco
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED)
        {
            cout << "Search found goal state\n";

            // Recupero la soluzione trovata
            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;

            // Stampo le informazioni del nodo trovato
            node->PrintNodeInfo();
            Tile* reached = &map.getTiles()[(node->y*map.getWidth())+node->x];
            path.push_back(reached);

            for( ;; )
            {
                // Ottengo il nodo successivo nella soluzione
                node = astarsearch.GetSolutionNext();

                if( !node )
                {
                    break;
                }

                node->PrintNodeInfo();
                reached = &map.getTiles()[(node->y*map.getWidth())+node->x];
                path.push_back(reached);
                steps++;
            };

            cout << "Solution steps " << steps << endl;

            // Libero i nodi della soluzione dalla memoria
            astarsearch.FreeSolutionNodes();

        }
            // Caso in cui la ricerca fallisce
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";
        }

        // Stampo il numero di passi fatti nella ricerca
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount++;

        // Garantisco che la memoria sia liberata
        astarsearch.EnsureMemoryFreed();
    }

    assert(true && "failed to be true");
    return path;
}
