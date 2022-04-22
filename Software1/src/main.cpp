/**
 * @file main.cpp
 * @author Mateo Felipe Umaña Gordillo
 * @brief Escuela Colombiana de ingeniería Julio Garavito
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>       /** Libreria para poder usar la funcion sleep()*/
#include <unistd.h>     
#include "tty_lib2.h"
#include "lib.h"
#define MAX 10          /** \brief Máxima cantidad de jugadores 10 */
#define BAUD_RATE   B9600  
using namespace std;

int main(int argc, char *argv[]){
    int play = 1;
    /**
     * \brief En el comando de ejecucion el primer argumento es la direccion del archivo .bin
     * el segundo es el tiempo de preparacion y el tercero la ventana de tiempo para realizar las
     * pulsaciones. Se deben ingresar los 3 argumentos exactamente.
     */
    if (argc != 3){
        cout <<"\n\n>>>Error: cantidad de parametros insuficientes. Por favor, ingrese los necesarios.\n\n\n";
    }else{
        while(play == 1){
            int cont, crono, players;
            int serial_port;
            struct termios tty;
            unsigned int yes_no = 0;
            int read_buf, num_bytes;
            participant participantes[MAX];
            config_tty ("/dev/ttyACM0", &tty, BAUD_RATE, &serial_port);
            for(cont = 0; cont < MAX; cont++){
                cout << "\nIngrese el participante No." << cont+1 << "\n" <<endl;
                participantes[cont].set_participant();
                players += 1;
                cout << "\n¿Desea ingresar otro participante?: (Si 1, No 0)\n";
                cin >> yes_no;
                if(yes_no == 0){
                    cont = MAX;
                }
            }
            cont = 0;
            for(cont = 0; cont < players; cont++){
                write(serial_port, "s", sizeof(char));
                cout << "\n..." << endl;
                cout << "..." << endl;
                cout << "..." << endl;
                sleep(strtol(argv[1],NULL,10));   //espera el tiempo de preparación, strtol convierte de cadena a long int
                write(serial_port, "r", sizeof(char));
                cout << "\nInicia!!!\n" << endl;
                sleep(strtol(argv[2],NULL,10)); //espera el tiempo de lectura
                num_bytes = read(serial_port, &read_buf, sizeof(read_buf));//read_buf contiene el caracter recibido por rx
                cout << num_bytes << "," << read_buf << endl;
                participantes[cont].set_pushed(read_buf);
                write(serial_port, "S", sizeof(char));
                if(players > 1){
                    cout << "\n\nSiguiente!!!\n" << endl;
                }
            }

            cout << "\n\n>>>¿Quiere volver a jugar?: (Si 1, No 0)" << endl;
            cin >> play;
            if(play == 1){
                cout << "\n\nAqui vamos de nuevo\n" << endl;
            }else{
                cout << "\n\nJuego terminado. Gracias.\n\n" << endl;
            }
            close(serial_port);
            for(cont = 0; cont < players; cont++){
                cout << "====================" << endl;
                cout << "     Resultados" << endl;
                cout << "====================" << endl;
                participantes[cont].print_results();
                cout << "\n\n";
            }
        }
        
    }
}