#ifndef LEVEL_H
#define LEVEL_H


class Level
{
    public:

    void reset();
    void inc();
    int getLevel();

    static Level* Instance()
        {
            if (instance == nullptr) instance = new Level();
            return instance;
        }

    protected:

    private:
        static Level* instance;
        int level;
};

#endif // LEVEL_H
