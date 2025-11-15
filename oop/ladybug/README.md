# Ladybug Game - Save/Load Funkcionalita

Jednoduchá JavaFX aplikace demonstrující ukládání a načítání konfigurace hry.

## Struktura projektu

```
oop/ladybug/
├── pom.xml                          # Maven konfigurace
└── src/
    ├── main/
    │   ├── java/cz/uhk/ladybug/
    │   │   ├── GameConfig.java          # Třída pro konfiguraci
    │   │   ├── ConfigManager.java       # Správce načítání/ukládání JSON
    │   │   ├── ScoreManager.java        # Správce skóre
    │   │   ├── LadyBugApp.java         # Hlavní aplikace
    │   │   └── MainMenuController.java  # Kontrolér pro UI
    │   └── resources/
    │       ├── config.json              # Výchozí konfigurace
    │       └── main-menu.fxml           # UI definice
    └── test/
        └── java/                        # Unit testy
```

## Funkce

### GameConfig.java
- Třída pro uchování konfigurace hry
- Obsahuje: obtížnost, uživatelské jméno, aktuální skóre, úroveň, vysoké skóre

### ConfigManager.java
- Správce pro načítání a ukládání konfigurace do JSON souboru
- Automatické vytvoření souboru s výchozími hodnotami, pokud neexistuje
- Error handling pro všechny operace se soubory
- Metody:
  - `loadConfig()` - načte konfiguraci
  - `saveConfig(GameConfig)` - uloží konfiguraci
  - `updateConfig(key, value)` - aktualizuje konkrétní hodnotu

### ScoreManager.java
- Správce skóre a vysokých skóre
- Automatická aktualizace high score
- Metody:
  - `addScore(points)` - přidá body
  - `getCurrentScore()` - vrátí aktuální skóre
  - `getHighScore()` - vrátí nejvyšší skóre
  - `resetCurrentScore()` - reset pro novou hru
  - `setLevel(level)` - nastaví úroveň

### LadyBugApp.java
- Hlavní JavaFX aplikace
- Inicializace manažerů
- Automatické uložení při ukončení aplikace

### MainMenuController.java
- Kontrolér pro hlavní menu
- Zobrazení statistik (skóre, úroveň)
- Možnost změny nastavení (jméno, obtížnost)
- Testovací tlačítka pro demonstraci funkcionality

## Spuštění

```bash
cd oop/ladybug
mvn clean install
mvn javafx:run
```

## Použité technologie

- Java 11+
- JavaFX 17
- Gson 2.10.1 (JSON zpracování)
- Maven

## Konfigurační soubor

Soubor `config.json` se vytvoří automaticky v kořenové složce aplikace s výchozími hodnotami:

```json
{
  "difficulty": "medium",
  "username": "Player",
  "currentScore": 0,
  "level": 1,
  "highScore": 0
}
```

## Error Handling

- Všechny operace se soubory mají ošetřené výjimky
- Při chybě načítání se použijí výchozí hodnoty
- Chybové hlášky se vypisují na standardní chybový výstup
- Aplikace pokračuje i při chybách ukládání/načítání
