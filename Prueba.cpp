#include <array>
#include <iomanip>
#include <iostream>
#include <functional>
#include <string>
#include "StringN.h"
#include <random>


#include <array>
#include <iomanip>
#include <iostream>
#include <functional>
#include <string>
#include "StringN.h"
#include <random>

struct Equipo
{
    std::string Nombre;
    std::string Confederación;
};

using EquiposBolillero = std::array<Equipo, 8>;
using EquiposGrupo = std::array<Equipo, 4>;

struct Bolillero
{
    unsigned Número;
    EquiposBolillero Equipos;
};

using Bolilleros = std::array<Bolillero, 4>;

struct Grupo
{
    char Letra;
    EquiposGrupo Equipos;
};

using Grupos = std::array<Grupo, 8>;

char Sortear(std::string&);
bool volverasortear(int, std::string const&, Grupos const&);

struct Registro
{
    char Letra;
    std::string País;
    std::string Confederación;
};

using Registros = std::array<Registro, 32>;

using Criterio = std::function<bool(Registro const&, Registro const&)>;

int main()
{
    Bolilleros const bolilleros =
    {{
        {
            1,
            {{
                { "Rusia",          "AFC"      },
                { "Alemania",       "UEFA"     },
                { "Brasil",         "Conmebol" },
                { "Portugal",       "UEFA"     },
                { "Argentina",      "Conmebol" },
                { "Bélgica",        "UEFA"     },
                { "Polonia",        "UEFA"     },
                { "Francia",        "UEFA"     }
            }}
        },
        {
            2,
            {{
                { "España",         "UEFA"     },
                { "Perú",           "Conmebol" },
                { "Suiza",          "UEFA"     },
                { "Inglaterra",     "UEFA"     },
                { "Colombia",       "Conmebol" },
                { "México",         "Concacaf" },
                { "Uruguay",        "Conmebol" },
                { "Croacia",        "UEFA"     }
            }}
        },
        {
            3,
            {{
                { "Dinamarca",      "UEFA"     },
                { "Islandia",       "UEFA"     },
                { "Costa Rica",     "Concacaf" },
                { "Suecia",         "UEFA"     },
                { "Túnez",          "CAF"      },
                { "Egipto",         "CAF"      },
                { "Senegal",        "CAF"      },
                { "Irán",           "AFC"      }
            }}
        },
        {
            4,
            {{
                { "Serbia",         "UEFA"     },
                { "Nigeria",        "CAF"      },
                { "Australia",      "AFC"      },
                { "Japón",          "AFC"      },
                { "Marruecos",      "CAF"      },
                { "Panamá",         "Concacaf" },
                { "Corea del Sur",  "AFC"      },
                { "Arabia Saudita", "AFC"      }
            }}
        },
    }};

    // Ejercicio 1
    void EscribirArchivoDeBolilleros(Bolilleros const&);
    EscribirArchivoDeBolilleros(bolilleros);

    // Ejercicio 2
    bool PreguntarSíONo(std::string const&);
    if (PreguntarSíONo("¿Desea Sortear Fase de Grupos?"))
    {
        void SortearEInformarGrupos(Bolilleros const&);
        SortearEInformarGrupos(bolilleros);
    }
    else
        std::exit(0);

    // Ejercicio 3
    void InformarListadosDeGrupos();
    InformarListadosDeGrupos();
}

void EscribirArchivoDeBolilleros(Bolilleros const& bolilleros)
{
}

bool PreguntarSíONo(std::string const& pregunta)
{
    return true;
}

void SortearEInformarGrupos(Bolilleros const& bolilleros)
{
    Grupos grupos =
    {{
        { 'A' },
        { 'B' },
        { 'C' },
        { 'D' },
        { 'E' },
        { 'F' },
        { 'G' },
        { 'H' }
    }};

    void SortearBolilleros(Bolilleros const&, Grupos&);
    SortearBolilleros(bolilleros, grupos);

    void GenerarArchivosGrupos(Grupos const&);
    GenerarArchivosGrupos(grupos);

    void InformarResultadosPorPantalla(Grupos const&);
    InformarResultadosPorPantalla(grupos);
}

void SortearBolilleros(Bolilleros const& bolilleros, Grupos& grupos)
{
    void SortearBolillero1(Bolilleros const&, Grupos&);
    SortearBolillero1(bolilleros, grupos);
    void SortearBolillero2(Bolilleros const&, Grupos&);
    SortearBolillero2(bolilleros, grupos);
    void SortearBolillero3(Bolilleros const&, Grupos&);
    SortearBolillero3(bolilleros, grupos);
    void SortearBolillero4(Bolilleros const&, Grupos&);
    SortearBolillero4(bolilleros, grupos);

}

void SortearBolillero1(Bolilleros const& bolilleros, Grupos& grupos)
{
    grupos.at(0).Equipos.at(0) = bolilleros.at(0).Equipos.at(0);

    std::string agrupos{ "BCDEFGH" };
    unsigned cantgrupos = agrupos.length();

    for (unsigned i = 1; i <= cantgrupos; ++i)
    {
        char gruposort{ Sortear(agrupos) };
        grupos.at(i).Equipos.at(0) = bolilleros.at(0).Equipos.at(gruposort - 'A');
    }
}

void SortearBolillero2(Bolilleros const& bolilleros, Grupos& grupos)
{
    std::string agrupos = "ABCDEFGH";
    int cantequip = agrupos.length();
    int control = 0;
    bool vof;

    for (int i=0; i<=cantequip; i++)
    {
        char gruposort;
        gruposort = Sortear(agrupos);

        vof = volverasortear (i, bolilleros.at(1).Equipos.at(gruposort - 'A').Confederación, grupos);
        if (vof == true)
        {
            i=0;
            agrupos = "ABCDEFGH";
        }
        else
        {
            grupos.at(i).Equipos.at(1) = bolilleros.at(1).Equipos.at(gruposort - 'A');
        }        
    }
}

void SortearBolillero3(Bolilleros const& bolilleros, Grupos& grupos)
{
}

void SortearBolillero4(Bolilleros const& bolilleros, Grupos& grupos)
{
}

char Sortear(std::string& asortear)
{
    unsigned cantsorteos{ asortear.length() };

    std::random_device rd;
    std::default_random_engine sorteo{ rd() };
    std::uniform_int_distribution<int> pos{ 0, asortear.length() - 1 };

    int posicion{ pos(sorteo) };
    char letragrupo{ asortear.at(posicion) };
    asortear.erase(posicion, 1);
    return letragrupo;
}
bool volverasortear(int grupoacomprobar, std::string const& confsorteada, Grupos const& grupos)
{
   std::string confacomprobar;
   int uefa = 0, conca = 0, afc = 0, conme = 0, caf = 0;

   for (int i=0; i<=3; i++)
   {
       confacomprobar = grupos.at(grupoacomprobar).Equipos.at(i).Confederación;
       if (confacomprobar == "UEFA"){
           uefa += 1;
           if (uefa >= 2 and confsorteada =="UEFA"){
               return true;
           }
       }
       if (confacomprobar == "Concacaf"){
           conca++;
           if (conca >= 1 and confsorteada =="Concacaf"){
               return true;
           }
       }
       if (confacomprobar == "AFC"){
           afc++;
           if (afc >= 1 and confsorteada =="AFC"){
               return true;
           }           
       }
       if (confacomprobar == "Conmebol"){
           conme++;
           if (conme >= 1 and confsorteada =="Conmebol"){
               return true;
           }           
       }
       if (confacomprobar == "CAF"){
           caf++;
           if (caf >= 1 and confsorteada =="CAF"){
               return true;
           }            
       }
   }
   return false;
}
void GenerarArchivosGrupos(Grupos const& grupos)
{
}

void InformarResultadosPorPantalla(Grupos const& grupos)
{
}

void InformarListadosDeGrupos()
{
    Registros registros;

    void LeerRegistrosDesdeArchivos(Registros&);
    LeerRegistrosDesdeArchivos(registros);

    void MostrarListados(Registros&);
    MostrarListados(registros);
}

void LeerRegistrosDesdeArchivos(Registros& registros)
{
}

void MostrarListados(Registros& registros)
{
    bool PorGrupo(Registro const&, Registro const&);
    bool PorPaís(Registro const&, Registro const&);
    bool PorConfederación(Registro const&, Registro const&);
    bool PorGrupoYConfederación(Registro const&, Registro const&);
    bool PorGrupoConfederaciónYPaís(Registro const&, Registro const&);

    std::array<Criterio, 5> criterios =
    {{
        PorGrupo,
        PorPaís,
        PorConfederación,
        PorGrupoYConfederación,
        PorGrupoConfederaciónYPaís
    }};

    for (auto const& criterio : criterios)
    {
        void OrdenarRegistros(Registros&, Criterio const&);
        OrdenarRegistros(registros, criterio);

        void MostrarListado(Registros const&);
        MostrarListado(registros);
    }
}

bool PorGrupo(Registro const& a, Registro const& b)
{
    return true;
}

bool PorPaís(Registro const& a, Registro const& b)
{
    return true;
}

bool PorConfederación(Registro const& a, Registro const& b)
{
    return true;
}

bool PorGrupoYConfederación(Registro const& a, Registro const& b)
{
    return true;
}

bool PorGrupoConfederaciónYPaís(Registro const& a, Registro const& b)
{
    return true;
}

void OrdenarRegistros(Registros& registros, Criterio const& criterio)
{
}

void MostrarListado(Registros const& registros)
{
}