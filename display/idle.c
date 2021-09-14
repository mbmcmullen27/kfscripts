#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#include "fetch.c"

int main(){

    WINDOW *title;

char* text1 = "  ___                  _     ___  _    _   ";
char* text2 = " |_ _|_ _  ___ ___ _ _| |_  |   \\(_)__| |__";
char* text3 = "  | || ' \\(_-</ -_) '_|  _| | |) | (_-< / /";
char* text4 = " |___|_||_/__/\\___|_|  \\__| |___/|_/__/_\\_\\";
                                           

    initscr();
    curs_set(0);

    int x = 0;
    int y = 0;

    int vx = 1;
    int vy = 1;

    int mx;
    int my;
    getmaxyx(stdscr,my,mx);
    mx=mx-47;
    my=my-4;
    /* create title window */
    title = newwin(4,47,y,x);
    if(title == NULL) {
        addstr("Unable to create window");
        refresh();
        getch();
    } else {
        waddstr(title,text1);
        wmove(title,1,0); 
        waddstr(title,text2);
        wmove(title,2,0);
        waddstr(title,text3);
        wmove(title,3,0);
        waddstr(title,text4);
        wrefresh(title);
        // wgetch(title);
    }


    int counter = 0;
    for(;;){
        // werase(stdscr);
        // wprintw(stdscr,"vy: %d, vx: %d",vy,vx);
        // refresh();
        if (counter % 100 == 0 && fetch() == 200) return(1);
        counter++;


        if (x+vx>=mx || x+vx<=0) vx = vx*(-1);
        if (y+vy>=my || y+vy<=0) vy = vy*(-1);

        y = y+vy;
        x = x+vx;
        werase(title);
        wrefresh(title);    

        mvwin(title,y,x);
        waddstr(title,text1);
        wmove(title,1,0);
        waddstr(title,text2);
        wmove(title,2,0);
        waddstr(title,text3);
        wmove(title,3,0);
        waddstr(title,text4);
        wrefresh(title);    
        usleep(50000);
    }

    endwin();
    return(0);
}
