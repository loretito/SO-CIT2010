/*
    Ejemplo de una shell interactiva con historial de comandos
    Solo esta implementado el historial con las flechas arriba y abajo

    Para compilar: gcc history.c -o history -lncurses

    IMPORTANTE!: Quizás necesites instalar ncurses

*/

#include <ncurses.h>
#include <string.h>

#define MAX_HISTORY 200
#define MAX_COMMAND 256

char history[MAX_HISTORY][MAX_COMMAND];
int h_counter = 0;
int current_h = -1;

void add_to_history(const char* command) {
    if (h_counter < MAX_HISTORY) {
        strcpy(history[h_counter], command);
        h_counter++;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++) {
            strcpy(history[i - 1], history[i]);
        }
        strcpy(history[MAX_HISTORY - 1], command);
    }
}

void clear_command_line(int row) {
    move(row, 0); 
    clrtoeol();   
    attron(COLOR_PAIR(1)); 
    printw("> "); 
    attroff(COLOR_PAIR(1)); 
    refresh();
}

int main() {
    initscr();
    start_color();
    use_default_colors();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // colores
    init_pair(1, COLOR_GREEN, -1); 
    init_pair(2, COLOR_YELLOW, -1); 
    init_pair(3, COLOR_CYAN, -1); 

    char command[MAX_COMMAND];
    int i = 0;
    int ch;
    int input_row = 2; 

    printw("Ejemplo para usar flechitas arriba/abajo para ver el historial:\n");
    refresh();
    move(input_row, 0);
    attron(COLOR_PAIR(1));
    printw("> ");
    attroff(COLOR_PAIR(1));
    refresh();

    while (1) {
        ch = getch();
        if (ch == '\n') {
            command[i] = '\0';

            if (i > 0) {
                // aqui es donde se recibe el comando cuando se presiona enter 
                add_to_history(command);
                current_h = h_counter;
                move(input_row, 0);
                clrtoeol();
                attron(COLOR_PAIR(1));
                printw("> ");
                attroff(COLOR_PAIR(1));
                attron(COLOR_PAIR(2));
                printw("%s", command);
                attroff(COLOR_PAIR(2));
                move(input_row - 1, 0);
                clrtoeol();
                attron(COLOR_PAIR(3));
                printw("%s", command);
                attroff(COLOR_PAIR(3));
                refresh();
            }
            i = 0;
            memset(command, 0, sizeof(command));
            move(input_row, 0);
            clear_command_line(input_row);
        } else if (ch == KEY_UP) {
            if (current_h > 0) {
                current_h--;
                strcpy(command, history[current_h]);
                i = strlen(command);
                clear_command_line(input_row);
                attron(COLOR_PAIR(2));
                printw("%s", command);
                attroff(COLOR_PAIR(2));
                refresh();
            }
        } else if (ch == KEY_DOWN) {
            if (current_h < h_counter - 1) {
                current_h++;
                strcpy(command, history[current_h]);
                i = strlen(command);
                clear_command_line(input_row);
                attron(COLOR_PAIR(2));
                printw("%s", command);
                attroff(COLOR_PAIR(2));
                refresh();
            } else {
                current_h = h_counter;
                i = 0;
                memset(command, 0, sizeof(command));
                clear_command_line(input_row);
            }
        } else if (ch == KEY_BACKSPACE || ch == 127) {
            if (i > 0) {
                i--;
                command[i] = '\0';
                clear_command_line(input_row);
                attron(COLOR_PAIR(2));
                printw("%s", command);
                attroff(COLOR_PAIR(2));
                refresh();
            }
        } else {
            if (i < MAX_COMMAND - 1) {
                command[i++] = ch;
                attron(COLOR_PAIR(2));
                addch(ch);
                attroff(COLOR_PAIR(2));
                refresh();
            }
        }
    }

    endwin();
    return 0;
}
