#include <iostream>
#include "MenuPrincipalManager.h" ///NO borrar


///---- MAI ----
using namespace std;

MenuPrincipalManager::MenuPrincipalManager(){
    setCantidadOpciones(9);
}
void MenuPrincipalManager::mostrarOpciones(){
        cout << "==================================================" << endl;
        cout << "       SISTEMA DE GESTION DE ORDENES MEDICAS      " << endl;
        cout << "==================================================" << endl;
        cout << " 1. GESTION DE AFILIADOS" << endl;
        cout << " 2. GESTION DE OBRAS SOCIALES" << endl;
        cout << " 3. GESTION DE ORDENES MEDICAS" << endl;
        cout << " 4. GESTION DE TIPOS DE ORDEN" << endl;
        cout << " 5. GESTION DE ORIGENES DE LA ORDEN" << endl;
        cout << " 6. GESTION DE AUTORIZACIONES" << endl;
        cout << " 7. GESTION DE MEDICOS" << endl;
        cout << " 8. GESTION DE ESPECIALIDADES" << endl;
        cout << " 9. GESTION DE INFORMES" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " 0. SALIR DEL SISTEMA" << endl;
        cout << "==================================================" << endl;

}

void MenuPrincipalManager::ejecutarOpcion(int opcion) {

     archObra.crearObrasSocialesPredeterminadas();
     //(Si tienen funciones similares para predeterminar Tipos de Orden U Origenes, las llamas aca)



        switch (opcion) {
            case 1:{
                am.Menu();
                break;
            }
            case 2:{
                osm.Menu();
                break;
            }
            case 3:{
                omm.menu();
                break;
            }
            case 4:{

                tom.menu();
                break;
            }
            case 5:{
                oom.menu();
                break;
            }
            case 6: {
                aut.menu();
                break;
            }
            case 7:{
                mm.run();
                break;
            }
            case 8: {
                em.run();
                break;
            }
            case 9: {
                im.run();
                break;
            }
            case 0:
                cout << endl << "Gracias por usar el sistema. Saliendo..." << endl;
                break;
            default:
                cout << endl << "OPCION INCORRECTA. Intente nuevamente" << endl;
                system("pause");
                break;
        }
    }
