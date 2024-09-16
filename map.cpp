//
// Creato da cosim il 08/08/2024.
//
#include "map.h"

// Definisco le texture come variabili globali per evitare di ricaricarle più volte
sf::Texture grassTexture;
sf::Texture wallTexture;
sf::Texture stepTexture;
sf::Texture limitTexture;

// Funzione per caricare tutte le texture necessarie per il gioco
void loadTextures() {
    static bool texturesLoaded = false; // Assicura che le texture vengano caricate solo una volta
    if (!texturesLoaded) {
        // Carico la texture dell'erba
        if (!grassTexture.loadFromFile("textures/grass.png")) {
            throw std::runtime_error("Impossibile caricare la texture grass.png");
        }

        // Carico la texture del muro
        if (!wallTexture.loadFromFile("textures/wall.png")) {
            throw std::runtime_error("Impossibile caricare la texture wall.png");
        }

        // Carico la texture del passo
        if (!stepTexture.loadFromFile("textures/step.png")) {
            throw std::runtime_error("Impossibile caricare la texture step.png");
        }

        // Carico la texture del limite
        if (!limitTexture.loadFromFile("textures/limit.png")) {
            throw std::runtime_error("Impossibile caricare la texture limit.png");
        }

        texturesLoaded = true; // Indica che le texture sono state caricate
    }
}

Map::Map(int width, int height) : width(width), height(height) {
    tiles.reserve(width * height); // Riservo spazio per tutte le tessere

    std::random_device rd;  // Generatore casuale di numeri
    rng = std::mt19937(rd());  // Inizializzo il generatore di numeri casuali

    loadTextures();  // Carico le texture

    // Inizializzo i tile della mappa
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int cost = generateRandomCost();  // Genero un costo casuale per il tile
            tiles.emplace_back(x, y, cost);  // Aggiungo il tile alla mappa
            if(cost == 9)
                tiles[(y*width)+x].shape.setTexture(&wallTexture);  // Imposto la texture del muro se il costo è 9 (non percorribile)
            else
                tiles[(y*width)+x].shape.setTexture(&grassTexture);  // Altrimenti imposto la texture dell'erba
        }
    }
}

// Funzione per disegnare la mappa nella finestra del gioco
void Map::draw(sf::RenderWindow &window) {
    sf::Font font;  // Carattere per mostrare il costo dei vari tile

    window.setActive(true);  // Rendo attiva la finestra per il rendering

    // Carico il font per i costi dei tile
    if (!font.loadFromFile("C:/Users/cosim/CLionProjects/astarsearch/font/gothic.ttf")) {
        throw std::runtime_error("Impossibile caricare il font gothic.ttf");
    }

    sf::Text costText;  // Oggetto di testo per visualizzare il costo delle tessere
    costText.setFont(font);
    costText.setCharacterSize(20);
    costText.setFillColor(sf::Color::Black);

    // Ciclo per disegnare tutte le tessere e mostrare i loro costi
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            Tile &tile = tiles[(y * width) + x];  // Prendo il tile corrente
            tile.draw(window);  // Lo disegno
            costText.setString(std::to_string(tile.cost));  // Imposto il testo con il costo del tile
            costText.setPosition(tile.shape.getPosition().x + 15, tile.shape.getPosition().y + 10);  // Posiziono il testo
            window.draw(costText);  // Disegno il testo
        }
    }
}

// Funzione che restituisce il costo del tile nella posizione (x, y)
int Map::GetMap( int x, int y )
{
    // Controllo se le coordinate sono fuori dai limiti della mappa
    if( x < 0 || x >= width || y < 0 || y >= height ) {
        return 9;  // Restituisco 9 se è fuori dai limiti (lo considero non percorribile)
    }

    return tiles[(y*width)+x].cost;  // Restituisco il costo del tile
}

// Funzione per generare un costo casuale per un tile (da 0 a 9)
int Map::generateRandomCost() {
    std::uniform_int_distribution<int> dist(0, 9);  // Definisco il range del costo
    return dist(rng);  // Genero e restituisco un costo casuale
}

// Funzione che cambia la texture del tile quando viene percorsa
void Map::walked(Tile *tile) {
    tile->shape.setTexture(&stepTexture);
}

// Funzione che cambia la texture della tessera a "limite"
void Map::limits(Tile *tile) {
    tile->shape.setTexture(&limitTexture);
}

// Funzione che imposta una tessera come muro
void Map::setwall(Tile *tile){
    tile->cost = 9;  // Imposto il costo della tessera a 9 (non percorribile)
    tile->shape.setTexture(&wallTexture);  // Cambio la texture
    tile->shape.setFillColor(sf::Color(200,0,0, 200));  // Imposto un colore per distinguere il muro aggiunto
}
