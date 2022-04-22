#ifndef LIB_H
#define LIB_H
    #include <iostream>
    #include <string>
    using namespace std;
    class participant{
        private:
            unsigned int part_id;
            string part_name;
            unsigned int num_pushed;
        public:     //prototipos de funciones, en participant.cpp esta la definicion de estas funciones
            participant();
            participant(unsigned int id, string name);
            void set_participant();
            void set_pushed(unsigned int cant);
            unsigned int get_id();
            string get_name();
            unsigned int get_pushed();
            void print_results();
    };
#endif