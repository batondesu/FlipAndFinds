#ifndef EVENT_H
#define EVENT_H
#include "SDL.h"

class Event
{


    public:

        Event() {} ;
        virtual ~Event() {} ;

        static Event* Instance()
            {
                if (instance == nullptr) instance = new Event();
                return instance;
            }

        SDL_Event Eve;

        int GetEvent();

        int GetRect(int lv);

        bool clickInRect(const SDL_Rect& r);

    protected:

    private:
    static Event* instance;

} ;



#endif // EVENT_H
