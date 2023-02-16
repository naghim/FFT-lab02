# Labor 02

Ahhoz, hogy az eseményeket a kezelőjükhöz tudjuk rendelni, szükséges a ```connect``` függvényt használni (dokumentáció [itt](https://doc.qt.io/qt-5/signalsandslots.html) és [itt](https://wiki.qt.io/New_Signal_Slot_Syntax)). Ennek alapvetően négy paramétere van: 1) az objektum, amelyen kiváltódott az esemény; 2) maga az esemény; 3) a fogadó/kezelő objektum; 4) a fogadó meghívandó függvénye. 

**Szintaxis:**
```cpp
connect(
    sender, SIGNAL( valueChanged(QString) ),  
    receiver, SLOT( updateValue(QString) )    // ahol a sender és a receiver is QObject* típusúak (vagyis pointerek)
);
```
**QT 5-től használható még:**
```cpp
connect(
    sender, &Sender::valueChanged,
    receiver, &Receiver::updateValue
);
```
vagy
```cpp
connect(
    sender, &Sender::valueChanged,
    someFunction                             // ahol someFunction lehet akár lambda is
);
```
## Feladatok

1.	QT Creator-ban hozzunk létre egy új „Qt Widgets Application” projektet. Mi a projekt struktúrája? Mi a .pro és .ui fájlok szerepe és formátuma? 

![project](https://user-images.githubusercontent.com/78269344/108048991-62aafe00-7050-11eb-96ab-aefab6a55139.png)

2.	Üres projektből ("Empty qmake Project") kiindulva, írjunk egy programot, mely gombnyomásra kilép az alkalmazásból. A sikeres kompiláláshoz mit kell a .pro fájlba beírni (```QT += …```)? 

```cpp
#include <QApplication> 
#include <QLabel>
#include <QPushButton> 
#include <QVBoxLayout> 
#include <QWidget>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget *window = new QWidget;
  QLabel *label = new QLabel("Hello GUI World!");
  QPushButton *button = new QPushButton("Quit!");
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  layout->addWidget(button);
  QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
  window->setLayout(layout);
  window->show();
  return app.exec();
}

```

3.	Bővítsük ki a 2. feladat grafikus felületét egy új gombbal, mely lenyomásra magyarul is kiírja a köszöntő üzenetet (```label->setText("...\n...");```).  Vezessünk be még egy gombot, melynek segítségével az üzenet láthatóságát tudjuk ki-be kapcsolni. Használjuk az ```isVisible()```, ```hide()```, ```show()``` metódusokat. 

6.	Készítsünk egy egyszerű alkalmazást, amelyben egy csuszkával (```QSlider```) állíthatunk egy digitális kijelzőn (```QLCDNumber```) megjelenő számot. 

<img width="300" alt="number display" src="https://i.ibb.co/vq0tMxm/display.png">
