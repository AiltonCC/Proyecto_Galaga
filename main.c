/**
 Equipo no.4: Baldal Namko
 
 Integrantes:
    Chavez Contreras Edgar Ailton Jave 
    Chávez Ríos Rodrigo
    Fuentes Herrera Carlos
    Velázquez Galván Diego Antonio
 
 Grupo: 1MV2
 
    Proyecto Galaga
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
#define FPS 60
#define SPEED 5
#define SPEEDMISIL -1
#define SPEEDLASER -1

#define true 1
#define false 0

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);   // Inicializa SDL
    IMG_Init(IMG_INIT_PNG);     // Inicializa IMG
    SDL_Rect nave, misil,title,alien1,alien2,disparo,disparo2,treinta,cuarenta,cincuenta,secenta,ochenta,cien,ochoscientos,cero;// Estructuras de las posiciones
    SDL_Event event;            // Variable para los eventos
    int running = true;         // Variable para el ciclo del videojuego
    int x_vel = 0,y_vel = 0,x_vel1 = 3, y_vel1 = 0,x_vel2=2,y_vel2=2;   // Variable para las velocidades
    int left_pressed = false;   // Variable para la tecla izquierda
    int right_pressed = false;  // Variable para la tecla derecha
    int space_pressed = false;  // Variable para la tecla espacio
    int cont2=0;

    // Crea la ventana
    SDL_Window *gWindow = SDL_CreateWindow("Bandal Namko - Galaga Remake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // Crea el renderizado de la ventana
    SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF); // Coloca la ventana en color negro

    SDL_Texture *gTexture = NULL;      // Textura de la nave
    SDL_Texture *gTextureDISP = NULL; // Textura del misil
    SDL_Texture *gTextureTitle = NULL; // Textura del titulo
    SDL_Texture *gTextureAlien1 = NULL; // Textura de la nave alien1
    SDL_Texture *gTextureAlien2 = NULL; // Textura de la nave alien2
    SDL_Texture *gTexturedisparo = NULL; // Textura del disparo enemigo
    SDL_Texture *gTexturedisparo2 = NULL; // Textura del disparo enemigo
    SDL_Texture *gTexture30 = NULL; // Textura del puntaje
    SDL_Texture *gTexture40 = NULL; // Textura del puntaje
    SDL_Texture *gTexture50 = NULL; // Textura del puntaje
    SDL_Texture *gTexture60 = NULL; // Textura del puntaje
    SDL_Texture *gTexture80 = NULL; // Textura del puntaje
    SDL_Texture *gTexture100 = NULL; // Textura del puntaje
    SDL_Texture *gTexture800 = NULL; // Textura del puntaje
    SDL_Texture *gTexture0 = NULL; // Textura del puntaje
    

    SDL_Surface *img = IMG_Load("titulo.png"); // Carga la iamgen del titulo
    gTextureTitle = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del titulo
    SDL_FreeSurface(img);

    img = IMG_Load("nave.png"); // Carga la imagen de la nave
    gTexture = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura de la nave
    SDL_FreeSurface(img);     

    img = IMG_Load("alien2.png"); // Carga la iamgen de la nave enemiga 1
    gTextureAlien1 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura de la nave
    SDL_FreeSurface(img);      

    img = IMG_Load("alien1.png"); // Carga la iamgen de la nave enemiga 1
    gTextureAlien2 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura de la nave
    SDL_FreeSurface(img);                             

    img = IMG_Load("misil.png"); // Carga la imagen del misil
    gTextureDISP = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del misil
    SDL_FreeSurface(img);

    img = IMG_Load("disparo.png"); // Carga la imagen del misil
    gTexturedisparo = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del disparo
    SDL_FreeSurface(img);

    img = IMG_Load("disparo2.png"); // Carga la imagen del misil
    gTexturedisparo2 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del disparo
    SDL_FreeSurface(img);

    img = IMG_Load("treinta.jpeg"); // Carga la imagen del puntaje
    gTexture30 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);

    img = IMG_Load("cuarenta.jpeg"); // Carga la imagen del puntaje
    gTexture40 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);

    img = IMG_Load("cincuenta.jpeg"); // Carga la imagen del puntaje
    gTexture50 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);

    img = IMG_Load("secenta.jpeg"); // Carga la imagen del puntaje
    gTexture60 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);
    
    img = IMG_Load("ochenta.jpeg"); // Carga la imagen del puntaje
    gTexture80 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);

    img = IMG_Load("cien.jpeg"); // Carga la imagen del puntaje
    gTexture100 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);

    img = IMG_Load("ochoscientos.jpeg"); // Carga la imagen del puntaje
    gTexture800 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);

    img = IMG_Load("cero.jpeg"); // Carga la imagen del puntaje
    gTexture0 = SDL_CreateTextureFromSurface(gRenderer, img); // Crea la textura del puntaje
    SDL_FreeSurface(img);



    // Posicion inicial de la nave
    // Dimenciones de la nave
    nave.x = 0;
    nave.y = SCREEN_HEIGHT - 100;
    nave.h = 100;
    nave.w = 100;

    // Posicion inicial de la nave enemiga 1
    // Dimenciones de la nave
    alien1.x = 0;
    alien1.y = 10;
    alien1.h = 60;
    alien1.w = 60;

    // Posicion inicial de la nave enemiga 2
    // Dimenciones de la nave
    alien2.x = 730;
    alien2.y = 80;
    alien2.h = 60;
    alien2.w = 60;

    //Posicion del misil
    misil.x=nave.x;
    misil.y=nave.y;
    misil.h=20;
    misil.w=20;

    //Posicion del misil enemigo
    disparo.x=alien1.x+17;
    disparo.y=alien1.y+42;
    disparo.h=25;
    disparo.w=25;

    //Posicion del misil enemigo 2
    disparo2.x=alien2.x+17;
    disparo2.y=alien2.y+42;
    disparo2.h=25;
    disparo2.w=25;

    //Posicion del titulo
    title.x=0;
    title.y=100;
    title.h=400;
    title.w=800;
    //Posición del score
        cero.x=700;
        cero.y=150;
        cero.h=40;
        cero.w=60;

    // Juego
    while (running)
    {
        y_vel += (space_pressed)*SPEEDMISIL; // La velocidad del misil al lanzarlo
        x_vel = (right_pressed - left_pressed) * SPEED; // Velocidad de la nave. Si presiona izquierda el movimiento sera negativo, si presiona derecha sera positivo.
                                                        //0 si no presiona nada.
        
        // Si ocurre un evento en el teclado
        while (SDL_PollEvent(&event))
        {
            // Para cerrar la ventana
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            // Cuando es presionada una tecla
            if (event.type == SDL_KEYDOWN)
            {
                title.h=0;
                title.w=0;
                
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE: // Espacio
                    space_pressed = true; // Tecla para el disparo de misiles  
                    break;
                case SDLK_LEFT: // Izquierda
                    left_pressed = true;
                    break;
                case SDLK_RIGHT: // Derecha
                    right_pressed = true;
                    break;
                }
            }
            // Cuando se suelta la tecla
            if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT: // Izquierda
                    left_pressed = false;
                    break;
                case SDLK_RIGHT: // Derecha
                    right_pressed = false;
                    break;
                }
            }

        }

        nave.x += x_vel; // Coordina el movimiento de la nave en x
        misil.x += x_vel; //Coordina el moviminto del disparo en x con la nave

        // Limita el movimiento en x (izquierda)
        if (nave.x < 0)
            nave.x = 0;

        // Limita el movimiento en x (derecha)
        if ((nave.x + nave.w) > SCREEN_WIDTH)
            nave.x = SCREEN_WIDTH - nave.w;

        // Limita el movimiento en y (abajo)
        if ((nave.y + nave.h) > SCREEN_HEIGHT)
            nave.y = SCREEN_HEIGHT - nave.h;
        //
        if (space_pressed == true) //Inicio del disparo
        {
            misil.y += y_vel; //Coordina el moviminto del disparo en y
        }
        
        if (misil.y < 0) //Fin del disparo
        {
            misil.x=nave.x;
            misil.y=nave.y;
            misil.h=20;
            misil.w=20;
            space_pressed = false;
            y_vel=0;
        }
       
       //alien 1
        alien1.x += x_vel1; // Coordina el movimiento de alien1 en x
        disparo.x += x_vel1; //Coordina el moviminto del disparo en x con alien1
        if(alien1.x + alien1.w > SCREEN_WIDTH){
           alien1.x = 0;
           disparo.x=alien1.x+17;
            disparo.y=alien1.y+42;
            x_vel1++;
        }
        //Limite de velocidad alien 1
        if(x_vel1>12){
            x_vel1=3;
        }
        //Disparo de alien 1
        disparo.y -= y_vel1-10;
      if(disparo.y >=SCREEN_HEIGHT){
        disparo.x=alien1.x+17;
            disparo.y=alien1.y;
            disparo.h=25;
            disparo.w=25;
            y_vel1=0;
      }

        //alien 2
        alien2.x -= x_vel2; // Coordina el movimiento de alien1 en x
        disparo2.x -= x_vel2; //Coordina el moviminto del disparo en x con alien1
        if(alien2.x + alien2.w < 0){
           alien2.x = SCREEN_WIDTH-alien2.w;
           disparo2.x=alien2.x+17;
            disparo2.y=alien2.y+42;
            x_vel2++;}

            //Limite de velocidad alien 2
        if(x_vel2>10){
            x_vel2=2;
        }

        //Disparo de alien 2
        disparo2.y -= y_vel2-10;
      if(disparo2.y >=SCREEN_HEIGHT){
        disparo2.x=alien2.x+17;
            disparo2.y=alien2.y;
            disparo2.h=25;
            disparo2.w=25;
            y_vel2=0;
      }

      //Colision 1
      if((alien1.y<=misil.y<=alien1.y+alien1.h)&&(misil.x==alien1.x+30)){
        alien1.x=0;
        cont2++;}

        //Colision 2
      if((alien2.y<=misil.y<=alien2.y+alien2.h)&&(misil.x==alien2.x+30)){
        alien2.x=SCREEN_WIDTH;
        cont2++;}

      //Colisión hacia usuario  
        if((nave.y<=disparo.y<=nave.y+nave.h)&&(disparo.x==nave.x+50)){
        nave.x=0;
        cont2--;}
        if((nave.y<=disparo2.y<=nave.y+nave.h)&&(disparo2.x==nave.x+50)){
        nave.x=0;
        cont2--;}
     switch (cont2) //Posicion de la puntuación
     {
     case 1: 
        treinta.x=700;
        treinta.y=150;
        treinta.h=40;
        treinta.w=60;

        cero.h=0;
        cero.w=0;
        cuarenta.h=0;
        cuarenta.w=0;
        break;
    case 2: 
        cuarenta.x=700;
        cuarenta.y=150;
        cuarenta.h=40;
        cuarenta.w=60;

        treinta.h=0;
        treinta.w=0;
        cero.h=0;
        cero.w=0;
        cincuenta.x=0;
        cincuenta.y=0;
        secenta.x=0;
        secenta.y=0;
        ochenta.x=0;
        ochenta.y=0;
        cien.x=0;
        cien.y=0;
        
        break;
    case 3: 
        cincuenta.x=700;
        cincuenta.y=150;
        cincuenta.h=40;
        cincuenta.w=60;

        cuarenta.x=0;
        cuarenta.y=0;
        treinta.h=0;
        treinta.w=0;
        cero.h=0;
        cero.w=0;
        secenta.x=0;
        secenta.y=0;
        ochenta.x=0;
        ochenta.y=0;
        cien.x=0;
        cien.y=0;
        
        break;
    case 4:
        secenta.x=700;
        secenta.y=150;
        secenta.h=40;
        secenta.w=60;
        
        cuarenta.x=0;
        cuarenta.y=0;
        cincuenta.x=0;
        cincuenta.y=0;
        treinta.h=0;
        treinta.w=0;
        cero.h=0;
        cero.w=0;
        ochenta.x=0;
        ochenta.y=0;
        cien.x=0;
        cien.y=0;
        
            break;
    case 5:
        ochenta.x=700;
        ochenta.y=150;
        ochenta.h=40;
        ochenta.w=60;

        secenta.x=0;
        secenta.y=0;
        cuarenta.x=0;
        cuarenta.y=0;
        cincuenta.x=0;
        cincuenta.y=0;
        treinta.h=0;
        treinta.w=0;
        cero.h=0;
        cero.w=0;
        cien.x=0;
        cien.y=0;
            break;
     default:
        cero.x=700;
        cero.y=150;
        cero.h=40;
        cero.w=60;

        break;
     }   
        // Limpia la pantalla
        SDL_RenderClear(gRenderer);
        // Renderiza las texturas
        SDL_RenderCopy(gRenderer, gTexture, NULL, &nave);
        SDL_RenderCopy(gRenderer, gTextureDISP, NULL, &misil);
        SDL_RenderCopy(gRenderer, gTextureTitle, NULL, &title);
        SDL_RenderCopy(gRenderer, gTextureAlien1, NULL, &alien1);
        SDL_RenderCopy(gRenderer, gTextureAlien2, NULL, &alien2);
        SDL_RenderCopy(gRenderer, gTexturedisparo, NULL, &disparo);
        SDL_RenderCopy(gRenderer, gTexturedisparo2, NULL, &disparo2);
        SDL_RenderCopy(gRenderer, gTexture30, NULL, &treinta);
        SDL_RenderCopy(gRenderer, gTexture40, NULL, &cuarenta);
        SDL_RenderCopy(gRenderer, gTexture50, NULL, &cincuenta);
        SDL_RenderCopy(gRenderer, gTexture60, NULL, &secenta);
        SDL_RenderCopy(gRenderer, gTexture80, NULL, &ochenta);
        SDL_RenderCopy(gRenderer, gTexture100, NULL, &cien);
        SDL_RenderCopy(gRenderer, gTexture800, NULL, &ochoscientos);
        SDL_RenderCopy(gRenderer, gTexture0, NULL, &cero);

        // Actualiza la pantalla
        SDL_RenderPresent(gRenderer);

        // FPS
        SDL_Delay(1000 / FPS);
    }

    // Destruye las texturas
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;
    SDL_DestroyTexture(gTextureDISP);
    gTexture = NULL;
    SDL_DestroyTexture(gTextureTitle);
    gTexture = NULL;
    SDL_DestroyTexture(gTextureAlien1);
    gTexture = NULL;
    SDL_DestroyTexture(gTextureAlien2);
    gTexture = NULL;
    SDL_DestroyTexture(gTexturedisparo);
    gTexture = NULL;
    SDL_DestroyTexture(gTexturedisparo2);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture30);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture40);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture50);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture60);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture80);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture100);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture800);
    gTexture = NULL;
    SDL_DestroyTexture(gTexture0);
    gTexture = NULL;


    // Destruye el render y la ventana
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quita el SDL del subsistema
    IMG_Quit();
    SDL_Quit();

    return 0;
}

