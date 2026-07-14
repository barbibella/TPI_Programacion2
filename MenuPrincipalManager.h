#pragma once
#include "MenuCls.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
#include "AfiliadoManager.h"
#include "OrdenMedicaManager.h"
#include "TipoDeOrdenManager.h"
#include "OrigenDeLaOrdenManager.h"
#include "AutorizacionManager.h"
#include "MedicoMenu.h"
#include "EspecialidadMenu.h"
#include "InformesMenu.h"

///---- MAI ----

class MenuPrincipalManager : public Menu
{
public:
    MenuPrincipalManager();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

private:
    AfiliadoManager am;
    ObraSocialManager osm;
    OrdenMedicaManager omm;
    TipoDeOrdenManager tom;
    OrigenDeLaOrdenManager oom;
    AutorizacionManager aut;
    MedicoMenu mm;
    EspecialidadMenu em;
    InformesMenu im;

    ObraSocialArchivo archObra;

};
