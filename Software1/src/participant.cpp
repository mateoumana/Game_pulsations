//#include <iostream>
//#include <string>
#include "lib.h"
/**
 * @brief lib.h contiene las declaraciones de las funciones y la clase
 * @brief participant.cpp contiene las definiciones de las funciones de la clase
 * 
 */
using namespace std;
/**
 * @brief Constructor
 * 
 * @return participant 
 */
participant :: participant():part_id(0),part_name(""),num_pushed(0){}
/**
 * @brief Constructor
 * 
 * @param id 
 * @param name 
 * @return participant 
 */
participant :: participant(unsigned int id, string name):part_id(id),part_name(name),num_pushed(0){}
/**
 * @brief Set the participant object
 * 
 * @return void
 */
void participant :: set_participant(){
    cout << "Ingrese el ID del participante:" << endl;
    cin >> part_id;
    cout << "Ingrese el nombre del participante:" << endl;
    cin >> part_name;
}
/**
 * @brief Set the pushed object
 * 
 * @param cant 
 */
void participant :: set_pushed(unsigned int cant){
    num_pushed = cant;
}
/**
 * @brief Get the id object
 * 
 * @return unsigned int 
 */
unsigned int participant :: get_id(){
    return part_id;
}
/**
 * @brief Get the name object
 * 
 * @return string 
 */
string participant :: get_name(){
    return part_name;
}
/**
 * @brief Get the pushed object
 * 
 * @return unsigned int 
 */
unsigned int participant :: get_pushed(){
    return num_pushed;
}
/**
 * @brief Print game results
 * 
 * @return void 
 */
void participant :: print_results(){
    cout << "Participante: " << part_name << endl;
    cout << "ID: " << part_id << endl;
    cout << "Pulsaciones: " << num_pushed << endl;
}