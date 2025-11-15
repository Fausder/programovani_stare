# Ladybug Game - Implementační Dokumentace

## Přehled

Tento projekt implementuje kompletní funkcionalitu pro ukládání a načítání konfigurace Ladybug hry do JSON formátu podle zadání.

## Implementované Komponenty

### 1. GameConfig.java
**Účel:** Datová třída pro uchování konfigurace hry

**Obsahuje:**
- `difficulty` (String) - obtížnost hry (easy, medium, hard)
- `username` (String) - uživatelské jméno hráče
- `currentScore` (int) - aktuální skóre
- `level` (int) - aktuální úroveň
- `highScore` (int) - nejvyšší dosažené skóre

**Výchozí hodnoty:**
- difficulty: "medium"
- username: "Player"
- currentScore: 0
- level: 1
- highScore: 0

### 2. ConfigManager.java
**Účel:** Správce pro načítání a ukládání konfigurace do JSON souboru

**Hlavní metody:**
- `loadConfig()` - Načte konfiguraci ze souboru, pokud neexistuje vytvoří nový s výchozími hodnotami
- `saveConfig(GameConfig)` - Uloží konfiguraci do souboru
- `updateConfig(String key, Object value)` - Aktualizuje konkrétní hodnotu v konfiguraci

**Error Handling:**
- Try-catch bloky pro všechny IO operace
- Validace načtených dat
- Výchozí hodnoty při chybě
- Informativní chybové hlášky

### 3. ScoreManager.java
**Účel:** Správce skóre a vysokých skóre

**Hlavní metody:**
- `addScore(int points)` - Přidá body k aktuálnímu skóre, automaticky aktualizuje high score
- `getCurrentScore()` - Vrátí aktuální skóre
- `getHighScore()` - Vrátí nejvyšší skóre
- `resetCurrentScore()` - Reset skóre pro novou hru
- `setLevel(int level)` - Nastaví úroveň hry
- `getLevel()` - Vrátí aktuální úroveň
- `reloadConfig()` - Znovu načte konfiguraci ze souboru

### 4. LadyBugApp.java
**Účel:** Hlavní JavaFX aplikace

**Funkce:**
- Inicializace ConfigManager a ScoreManager při startu
- Načtení FXML uživatelského rozhraní
- Automatické uložení konfigurace při ukončení aplikace (metoda `stop()`)
- Statické gettery pro přístup k manažerům

### 5. MainMenuController.java
**Účel:** Kontrolér pro hlavní menu hry

**Funkce:**
- Zobrazení aktuálních statistik (skóre, level, high score)
- Možnost změny uživatelského jména
- Výběr obtížnosti z ComboBoxu
- Testovací tlačítka:
  - "Nová hra" - Reset skóre
  - "Přidat body" - Demonstrace přidání bodů
  - "Reset" - Reset celého skóre
  - "Uložit" - Ruční uložení nastavení

### 6. config.json
**Umístění:** `src/main/resources/config.json` (výchozí šablona)
**Runtime umístění:** Kořenový adresář aplikace

**Formát:**
```json
{
  "difficulty": "medium",
  "username": "Player",
  "currentScore": 0,
  "level": 1,
  "highScore": 0
}
```

## Testování

### Unit Testy (ConfigManagerTest.java)
Všech 8 testů prošlo úspěšně:

1. `testDefaultConfig` - Ověření výchozích hodnot
2. `testSaveAndLoadConfig` - Test ukládání a načítání
3. `testUpdateConfig` - Test aktualizace konfigurace
4. `testScoreManagerAddScore` - Test přidávání bodů
5. `testScoreManagerHighScore` - Test high score logiky
6. `testScoreManagerLevel` - Test správy úrovní
7. `testScoreManagerReset` - Test resetu skóre
8. `testConfigFileCreation` - Test vytvoření souboru

### Výsledky Buildů
- **Kompilace:** ✅ Úspěšná
- **Testy:** ✅ 8/8 prošlo
- **Package:** ✅ JAR vytvořen úspěšně

### Bezpečnost
- **GitHub Advisory Database:** ✅ Žádné zranitelnosti v závislostech
- **CodeQL Scan:** ✅ Žádné bezpečnostní problémy (0 alerts)

## Použité Technologie

- **Java:** 11+
- **JavaFX:** 17.0.2
- **Gson:** 2.10.1 (JSON zpracování)
- **JUnit Jupiter:** 5.9.2 (testování)
- **Maven:** Build systém

## Spuštění Aplikace

```bash
cd oop/ladybug
mvn clean install
mvn javafx:run
```

## Spuštění Testů

```bash
cd oop/ladybug
mvn test
```

## Splněné Požadavky

✅ **GameConfig.java** - Třída pro uchování konfigurace
✅ **ConfigManager.java** - Správce pro načítání/ukládání do JSON
✅ **ScoreManager.java** - Správce skóre a vysokých skóre
✅ **config.json** - Konfigurační soubor v resources
✅ **Integrace do LadyBugApp.java a MainMenuController.java**
✅ **Jednoduché řešení bez zbytečností**
✅ **JSON formát pro config a skóre**
✅ **Automatické vytvoření souboru s výchozími hodnotami**
✅ **Ukládání: obtížnost, uživatelské jméno, aktuální skóre, vysoké skóre**
✅ **Bez přebytečných funkcí - jen skutečně používané**
✅ **Error handling pro případ chyby při načítání/ukládání**

## Poznámky k Implementaci

1. **Minimalistický Přístup:** Implementace obsahuje pouze požadované funkce bez zbytečných rozšíření
2. **Robustní Error Handling:** Všechny IO operace jsou ošetřené s fallback na výchozí hodnoty
3. **Testovatelnost:** Všechny komponenty jsou samostatně testovatelné
4. **Automatizace:** Config se vytvoří automaticky, uloží se při ukončení aplikace
5. **Jednoduchost:** Jasná separace zodpovědností mezi třídami

## Struktura Souborů

```
oop/ladybug/
├── pom.xml                          # Maven konfigurace
├── .gitignore                       # Ignorování build artifacts
├── README.md                        # Základní dokumentace
├── IMPLEMENTATION.md                # Tato dokumentace
└── src/
    ├── main/
    │   ├── java/cz/uhk/ladybug/
    │   │   ├── GameConfig.java          # Datová třída
    │   │   ├── ConfigManager.java       # JSON manager
    │   │   ├── ScoreManager.java        # Score manager
    │   │   ├── LadyBugApp.java         # Hlavní aplikace
    │   │   └── MainMenuController.java  # UI kontrolér
    │   └── resources/
    │       ├── config.json              # Výchozí config
    │       └── main-menu.fxml           # UI layout
    └── test/
        └── java/cz/uhk/ladybug/
            └── ConfigManagerTest.java    # Unit testy
```
