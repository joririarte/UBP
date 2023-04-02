//
// Created by raugu on 25/3/2023.
//

#ifndef AED_EJ3_RAICES_H
#define AED_EJ3_RAICES_H

namespace std {

    class Raices {
        private:
            double a;
            double b;
            double c;
        public:
            Raices(double a, double b, double c);
            void obtenerRaices();
            void obtenerRaiz();
            double getDiscriminante();
            bool tieneRaices();
            bool tieneRaiz();
            void calcular();


    };

} // std

#endif //AED_EJ3_RAICES_H
