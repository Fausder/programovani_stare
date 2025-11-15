package cz.uhk.ladybug;

/**
 * Správce skóre a vysokých skóre.
 * Využívá ConfigManager pro persistenci dat.
 */
public class ScoreManager {
    private final ConfigManager configManager;
    private GameConfig currentConfig;

    public ScoreManager(ConfigManager configManager) {
        this.configManager = configManager;
        this.currentConfig = configManager.loadConfig();
    }

    /**
     * Přidá body k aktuálnímu skóre.
     */
    public void addScore(int points) {
        int newScore = currentConfig.getCurrentScore() + points;
        currentConfig.setCurrentScore(newScore);
        
        // Aktualizace high score, pokud je překonáno
        if (newScore > currentConfig.getHighScore()) {
            currentConfig.setHighScore(newScore);
            System.out.println("Nové vysoké skóre: " + newScore);
        }
        
        configManager.saveConfig(currentConfig);
    }

    /**
     * Vrátí aktuální skóre.
     */
    public int getCurrentScore() {
        return currentConfig.getCurrentScore();
    }

    /**
     * Vrátí vysoké skóre.
     */
    public int getHighScore() {
        return currentConfig.getHighScore();
    }

    /**
     * Resetuje aktuální skóre (např. na začátku nové hry).
     */
    public void resetCurrentScore() {
        currentConfig.setCurrentScore(0);
        currentConfig.setLevel(1);
        configManager.saveConfig(currentConfig);
        System.out.println("Skóre resetováno.");
    }

    /**
     * Nastaví úroveň hry.
     */
    public void setLevel(int level) {
        currentConfig.setLevel(level);
        configManager.saveConfig(currentConfig);
    }

    /**
     * Vrátí aktuální úroveň.
     */
    public int getLevel() {
        return currentConfig.getLevel();
    }

    /**
     * Reload konfigurace ze souboru.
     */
    public void reloadConfig() {
        this.currentConfig = configManager.loadConfig();
    }

    /**
     * Vrátí aktuální konfiguraci.
     */
    public GameConfig getCurrentConfig() {
        return currentConfig;
    }
}
