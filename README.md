# Joc tubing
## Obiectiv joc:
Jucatorul este tras de barca cu un colac. Acesta trebuie sa evite obstacolele si sa sara peste ele pentru a obtine punctaj mai mare. Pentru a sari, jucatorul va apasa Left-Click pentru a ramane in aer pentru cateva secunde. Cand acesta este pe apa, daca se va lovi de obstacole, va fi imediat invulnerabil la lovituri pentru cateva secunde. Jucatorul acumuleaza cate un punct pentru fiecare secunda supravietuita, si cate 25 de puncte pentru sarirea peste obstacole. Peste unele obstacole se poate sari, iar peste altele nu.
## Structura codului:
### Clasa Game
Clasa Game este folosita pentru a rula jocul principal. Ea gestioneaza tot procesul de rulare al jocului, comportandu-se ca un coordonator al fiecarei componente.
#### Metoda processEvents
Metoda processEvents() trimite semnalul de inchidere al ferestrei daca este cazul, si in rest trimite mai departe orice semnal primit catre InputManager (responsabil pentru input, dupa nume).
#### Metoda run
Punctul de plecare al rularii jocului. Ea incepe orchestrarea componentelor jocului.
### Clasa InputManager
Clasa InputManager este folosita strict pentru un Singleton care gestioneaza tot input-ul din joc. El trimite semnalele mai departe la "handlers", pentru ca ele sa notifice obiectele abonate ca sa raspunda la semnalul respectiv, conform design pattern-ului Observer.
#### Metoda addHandler
Metoda addHandler primeste un pointer unic la "handler" pentru a-i prelua ownership-ul. Acesta este adaugat in reprezentarea interna de handleri (un vector pentru a lasa orice clasa sa adauge un handler, fara a cupla InputManager de nimic)
#### Metoda clearHandlers
Metoda clearHandlers este folosita pentru a goli handlerii la tranzitionarea catre o alta stare de joc.
#### Metoda processEvent
Metoda processEvent primeste acel semnal care trebuie procesat, ca sa il trimita mai departe la toti "handlers".
### Clasa GameState
Clasa GameState este o interfata pentru ca fiecare stare de joc concreta sa aiba o interfata peste care sa construiasca. Astfel, obliga aceste stari de joc sa adere la o conventie si sa precizeze noua stare spre care tranzitioneaza.
#### Metoda run
Metoda run are un algoritm simplu: primeste timp delta si initializeaza starea daca este abia "pornita". Apoi, apeleaza subrutina de actualizare si randare a continutului.
#### Metoda init
Metoda init este optionala, in caz ca starea mai trebuie sa execute niste operatii inainte de a ajunge in stare de rulare.
#### Metoda update
Metoda update face ca continutul prezentat sa se actualizeze in functie de regulile precizate fiecarui obiect.
#### Metoda render
Metoda render face ca continutul grafic sa apara in fereastra jocului, in starea in care este la momentul de fata.
#### Metoda getNewState
Metoda getNewState forteaza o conventie asupra utilizatorului acestei interfete: clasa Game tot apeleaza aceasta metoda pentru a obtine o stare noua pentru a tranzitiona. Aceasta metoda trebuie implementata pentru a specifica cazul de tranzitionare sau de repaos. Pentru a nu tranzitiona, se returneaza nullptr.
### Clasa Drawable
Clasa Drawable este o interfata care forteaza pe cei care o mostenesc sa implementeze modul in care se deseneaza obiectul/obiectele pe ecran (vezi mai jos).
#### Metoda draw
Metoda draw primeste un RenderTarget, din SFML stiut ca un loc unde se pot desena obiecte concrete (in cazul nostru numai o fereastra). Partea geniala este ca, in realitate apelarea target.draw() se poate face doar pe obiecte implementate de SFML, cum ar fi RectangleShape, CircleShape... dar aceasta metoda permite inlantuirea mai multor implementari de draw. Exemplu: daca clasa Player trebuie sa deseneze clasa Boat, clasa Rope si clasa Tube, atunci trimite mai departe acestora aceasta responsabilitate (apeleaza metoda draw a lor, pana cand se ajunge eventual la forme SFML concrete).
### Clasa Updatable
Clasa Updatable este o interfata care forteaza pe cei care o mostenesc sa implementeze modul in care se actualizeaza obiectul/obiectele pe ecran.
#### Metoda update
Metoda update primeste un numar real deltaTime (o reprezentare a cat timp a trecut intr-o secunda de timp real, sub forma unui numar subunitar) cu ajutorul careia se poate ajusta timpul de executie al anumitor interactiuni din joc, astfel incat sa arate la fel pe toate calculatoarele (jocul nu va rula mai repede daca ai un calculator mai performant, sau mai incet daca ai un calculator mai putin performant)
### Clasa Collidable
Clasa Collidable este o interfata care forteaza pe cei care o mostenesc sa implementeze doua lucruri: sa returneze un asa numit "Bounding Box" (un dreptunghi care reprezinta dimensiunea reala a obiectului) care este folosit la operatii de verificat coliziunea de anumite obiecte, si o operatie care sa fie executata in urma coliziunii cu cate un obiect anume.
#### Metoda getBounds
Metoda getBounds returneaza o reprezentare in SFML a acestui "Bounding Box" numita FloatRect. Cum este calculata aceasta depinde de clasele derivate.
#### Metoda onCollision
Metoda onCollision pune la dispozitie claselor derivate un mod de a accesa obiectul cu care au format o coliziune. Pentru a accesa acest obiect, este nevoie de downcast. Se pot aplica reguli pentru a modela anumite actiuni in urma coliziunii cu anumite obiecte.
### Clasa InputHandler
Clasa InputHandler este o interfata pentru a deriva noi "handlers" de input. Aceasta forteaza gestionarea semnalului primit cu metoda handleEvent.
#### Metoda handleEvent
Metoda handleEvent primeste un semnal ca parametru pentru a-l prelucra mai departe.
### Clasa MouseListener
Clasa MouseListener este o interfata pentru a defini actiunile unui obiect abonat la operatiile legate de mouse, in 3 cazuri: la miscarea lui, la apasarea butonului click si la eliberarea click-ului.
### Clasa MouseInputHandler
Clasa MouseInputHandler este un InputHandler care tine cont de cererile abonatilor si suprascrie prin polimorfism metoda de gestionare a semnalului, pentru a trimite mai departe semnalele primite de la mouse.
#### Metoda addListener
Metoda addListener adauga un abonat la reprezentarea interna.
#### Metoda handleEvent
Metoda handleEvent trimite mai departe semnalul abonatilor.
### Clasa Button
Clasa Button este o interfata care forteaza o regula asupra tuturor butoanelor: la eliberarea click-ului inauntrul butonului, se lanseaza o comanda (metoda command), o actiune.
#### Metoda onMouseReleased
Metoda onMouseReleased este o strategie pentru input-ul transmis catre buton. Daca click-ul este eliberat inauntrul lui in urma unei apasari, se lanseaza comanda corespunzatoare butonului (clasele derivate trebuie sa o implementeze).
#### Metoda command
Metoda command forteaza implementarea unei comenzi in urma apasarii butonului.
#### Metoda clickedInside
Metoda clickedInside forteaza clasele de butoane concrete sa implementeze un mod de a verifica daca coordonatele cursorului se afla inauntrul butonului.
### Clasa StartState
Clasa StartState reprezinta starea de inceput a jocului, care afiseaza ecranul cu titlul si butonul de a incepe jocul.
### Clasa PlayState
Clasa PlayState reprezinta starea de rulare a jocului interactiv propriu-zis, care contine toate componentele aferente acesteia.
### Clasa EndState
Clasa EndState reprezinta starea de sfarsit a jocului, care semnaleaza utilizatorului ca jocul a avut sfarsit.
### Clasa Player
Clasa Player este responsabila pentru toate obiectele care sunt modelate in jurul interactiunilor jucatorului cu jocul in sine, si orchestrarea actiunilor acestora.
#### Metode de initializare
Metodele de initializare sunt un mod de a modulariza codul, astfel incat sa fie mai usor de gasit si modificat anumite valori setate arbitrar.
#### Metoda tryIncrementingScoreByTime
Metoda tryIncrementingScoreByTime incearca mereu cresterea scorului pentru timpul trecut de la ultima secunda, si actualizeaza cu adevarat aceasta valoare pe secunda reala care trece.
#### Metoda incrementScoreByTime
Metoda incrementScoreByTime chiar realizeaza operatia de crestere a scorului dupa o secunda.
#### Metoda resetElapsedTime
Metoda resetElapsedTime seteaza timpul inapoi la zero dupa ce chiar a trecut o secunda, pentru a contoriza din nou timpul pana la urmatoarea secunda.
#### Metoda drawAllTrails
Metoda drawAllTrails semnaleaza desenarea urmelor lasate pe apa de catre colac.
#### Metoda getPlayerLives
Metoda getPlayerLives returneaza un pointer distribuit catre numarul de vieti ale jucatorului. Acesta este distribuit intre Player, HUD si PlayState.
### Clasa Boat
Clasa Boat reprezinta barca care trage colacul cu franghia.
#### Metoda getAnchor
Metoda getAnchor returneaza coordonatele la punctul de ancorare al franghiei de barca. Aceasta metoda este utila pentru anumite calcule referitoare la rotatia franghiei si miscarea colacului.
### Clasa LineSegment
Clasa LineSegment este o abstractie pentru forma geometrica de segment, de o anumita lungime si grosime. A fost facuta cu scopul de a putea seta un punct de plecare si un punct de destinatie, pentru a desena un segment in functie de aceste valori.
### Clasa Rope
Clasa Rope foloseste un obiect de tip LineSegment explicat anterior pentru a desena un segment (franghia) in mod constant de la punctul de ancorare al barcii pentru franghie, pana la punctul de ancorare al colacului pentru franghie (punctele de care aceasta franghie este legata).
### Clasa Tube
Clasa Tube reprezinta o multitudine de abstractii pentru a modela comportamentele colacului, si anume miscarea colacului, modalitatea acestuia de a sari, ramane in aer si ateriza, a se ciocni de alte obiecte si a deveni invulnerabil pentru scurt timp in urma ciocnirii.
#### Metodele referitoare la Shadow
Metodele referitoare la Shadow sunt pentru a gestiona umbra care apare in timp ce colacul este in aer si dispare cand acesta aterizeaza.
#### Metodele referitoare la AirTime
Metodele referitoare la AirTime sunt pentru a gestiona procesul de a ramane in aer pentru o anumita durata, a declansa si a opri aceasta stare a colacului.
### Functiile TubePos
Functiile TubePos sunt diverse functii ajutatoare pentru calcule matematice, cum ar fi constrangerea unei valori intre doua capete arbitrare si obtinerea miscarii in forma de semicerc prin formule deduse cu geometrie analitica (teorema lui Pitagora, trigonometrie).
### Clasa CollisionManager
Clasa CollisionManager este responsabila pentru un singur lucru, verificarea coliziunii jucatorului cu obstacolele. Apoi, in urma coliziunii, de a trimite semnalul reciproc de coliziune, de la jucator la obstacol, si de la obstacol la jucator.
### Clasa Obstacle
Clasa Obstacle este o generalizare a obstacolului si ofera diverse abstractii pentru actiuni referitoare cu acesta. Ea a fost conceputa pentru clonare dupa un template (nu template din C++, o colectie de tipuri separate de obstacole).
### Clasa ObstacleManager
Clasa ObstacleManager este responsabila pentru gestiunea obstacolelor care se afla pe ecran (active) si a template-ului de obstacole discutat mai sus. Acesta functioneaza ca un design pattern de Abstract Factory, obstacolele fiind Prototypes. Se poate regla intervalul de creatie a obstacolelor noi si obstacolele in sine care pot aparea.
### Clasa ObstacleSpawner
Clasa ObstacleSpawner are responsabilitatea de a genera obstacole concrete noi, aleator de la o coordonata la alta pe orizontala. Este folosita in principiu de ObstacleManager.
### Tipuri de obstacole
Tipurile de obstacole demonstrate sunt balizele (Buoy) si stancile (Rock). Ideea demonstratiei era sa existe un obiect peste care se poate sari (stanca) si un obiect peste care nu se poate sari, deoarece este prea inalt (baliza).


### Bibliografia este in fisierul bibliografie.txt.
### Graficile sunt folosite ca placeholders si sunt orientative.

# CMake SFML Project Template

This repository template should allow for a fast and hassle-free kick start of your next SFML project using CMake.
Thanks to [GitHub's nature of templates](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template), you can fork this repository without inheriting its Git history.

The template starts out very basic, but might receive additional features over time:

- Basic CMake script to build your project and link SFML on any operating system
- Basic [GitHub Actions](https://github.com/features/actions) script for all major platforms

## How to Use

1. Install [Git](https://git-scm.com/downloads) and [CMake](https://cmake.org/download/). Use your system's package manager if available.
2. Follow [GitHub's instructions](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template) for how to use their project template feature to create your own project. If you don't want to use GitHub, see the section below.
3. Clone your new GitHub repo and open the repo in your text editor of choice.
4. Open [CMakeLists.txt](CMakeLists.txt). Rename the project and the target name of the executable to whatever name you want. Make sure to change all occurrences.
5. If you want to add or remove any .cpp files, change the source files listed in the `add_executable` call in CMakeLists.txt to match the source files your project requires. If you plan on keeping the default main.cpp file then no changes are required.
6. If your code uses the Audio or Network modules then add `SFML::Audio` or `SFML::Network` to the `target_link_libraries` call alongside the existing `SFML::Graphics` library that is being linked.
7. If you use Linux, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
   ```
   sudo apt update
   sudo apt install \
       libxrandr-dev \
       libxcursor-dev \
       libxi-dev \
       libudev-dev \
       libfreetype-dev \
       libflac-dev \
       libvorbis-dev \
       libgl1-mesa-dev \
       libegl1-mesa-dev \
       libfreetype-dev
   ```
8. Configure and build your project. Most popular IDEs support CMake projects with very little effort on your part.

   - [VS Code](https://code.visualstudio.com) via the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
   - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)
   - [CLion](https://www.jetbrains.com/clion/features/cmake-support.html)
   - [Qt Creator](https://doc.qt.io/qtcreator/creator-project-cmake.html)

   Using CMake from the command line is straightforward as well.
   Be sure to run these commands in the root directory of the project you just created.

   ```
   cmake -B build
   cmake --build build
   ```

9. Enjoy!

## Upgrading SFML

SFML is found via CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) module.
FetchContent automatically downloads SFML from GitHub and builds it alongside your own code.
Beyond the convenience of not having to install SFML yourself, this ensures ABI compatibility and simplifies things like specifying static versus shared libraries.

Modifying what version of SFML you want is as easy as changing the `GIT_TAG` argument.
Currently it uses SFML 3 via the `3.0.0` tag.

## But I want to...

Modify CMake options by adding them as configuration parameters (with a `-D` flag) or by modifying the contents of CMakeCache.txt and rebuilding.

### Not use GitHub

You can use this project without a GitHub account by [downloading the contents](https://github.com/SFML/cmake-sfml-project/archive/refs/heads/master.zip) of the repository as a ZIP archive and unpacking it locally.
This approach also avoids using Git entirely if you would prefer to not do that.

### Change Compilers

See the variety of [`CMAKE_<LANG>_COMPILER`](https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER.html) options.
In particular you'll want to modify `CMAKE_CXX_COMPILER` to point to the C++ compiler you wish to use.

### Change Compiler Optimizations

CMake abstracts away specific optimizer flags through the [`CMAKE_BUILD_TYPE`](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html) option.
By default this project recommends `Release` builds which enable optimizations.
Other build types include `Debug` builds which enable debug symbols but disable optimizations.
If you're using a multi-configuration generator (as is often the case on Windows), you can modify the [`CMAKE_CONFIGURATION_TYPES`](https://cmake.org/cmake/help/latest/variable/CMAKE_CONFIGURATION_TYPES.html#variable:CMAKE_CONFIGURATION_TYPES) option.

### Change Generators

While CMake will attempt to pick a suitable default generator, some systems offer a number of generators to choose from.
Ubuntu, for example, offers Makefiles and Ninja as two potential options.
For a list of generators, click [here](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html).
To modify the generator you're using you must reconfigure your project providing a `-G` flag with a value corresponding to the generator you want.
You can't simply modify an entry in the CMakeCache.txt file unlike the above options.
Then you may rebuild your project with this new generator.

## More Reading

Here are some useful resources if you want to learn more about CMake:

- [Official CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [How to Use CMake Without the Agonizing Pain - Part 1](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-1.html)
- [How to Use CMake Without the Agonizing Pain - Part 2](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-2.html)
- [Better CMake YouTube series by Jefferon Amstutz](https://www.youtube.com/playlist?list=PL8i3OhJb4FNV10aIZ8oF0AA46HgA2ed8g)

## License

The source code is dual licensed under Public Domain and MIT -- choose whichever you prefer.
