
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 700;

SDL_Texture* loadTexture(string path);

SDL_Window*   gWindow_   = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture*  gTexture  = NULL;
SDL_Texture*  gObject   = NULL;
SDL_Rect     Toado;
SDL_Rect     ToaDo;


bool Init()
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        success = false;
	else
	{
		gWindow_ = SDL_CreateWindow( "Flip And Finds", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow_ == NULL )
			success = false;
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow_, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
				success = false;
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
					success = false;
			}
		}
	}

	return success;
}

string ToString(int n) {
    string s;
    while( n ) {
        s = char( n % 10 + 48 ) + s;
        n /= 10;
    }

    return s;
}

bool loadMedia(string s)
{
    bool success = true;
    string s1 = "Image/";
    string s2 = ".jpg";

	gTexture = loadTexture( s1 + s + s2 );

    if ( gTexture == NULL ) success = false;

	return success;
}

void close()
{
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow_ );
	gWindow_ = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

	if( loadedSurface != NULL ) {

        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		SDL_FreeSurface( loadedSurface );

        /*if (newTexture != NULL){
            UINT32 color_key = SDL_MapRGB(newTexture->format, 0xFF , 0xFF, 0xFF , 0xFF);
            SDL_SetColorKey(newTexture, SDL_SRCCOLORKEY, color_key);
        }*/

	}

	return newTexture;
}


int main( int argc, char* args[] )
{
	Init();

    loadMedia("BgrCovid");
    SDL_RenderCopy( gRenderer, gTexture, NULL , NULL );
    SDL_RenderPresent( gRenderer );

    bool quit = false;
    SDL_Event e;

        int x = 10 , y = 10 ;
        for (int i = 1 ; i <= 16 ; ++i) {

            Toado.x = 0;        ToaDo.x = x;
            Toado.y = 0;        ToaDo.y = y;
            Toado.w = 900;      ToaDo.w = 70;
            Toado.h = 544;      ToaDo.h = 70;

            loadMedia( ToString(i%8+1) );
          //  SDL_RenderClear( gRenderer );
            SDL_RenderCopy( gRenderer, gTexture, &Toado, &ToaDo );
            SDL_RenderPresent( gRenderer );

            x += 80;
            if ( i%4 == 0 ) {
                y += 80;
                x = 10;
            }

        }

        SDL_Event click;


        while( !quit ){
            while( SDL_PollEvent( &e ) != 0 ){
                if( e.type == SDL_QUIT )
                    quit = true;
            }

        }

	close();
	return 0;
}
