package cz.uhk.ladybug;

/**
 * Třída pro uchování konfigurace hry.
 * Obsahuje základní nastavení jako obtížnost, uživatelské jméno, skóre a úroveň.
 */
public class GameConfig {
    private String difficulty;
    private String username;
    private int currentScore;
    private int level;
    private int highScore;

    /**
     * Výchozí konstruktor s defaultními hodnotami.
     */
    public GameConfig() {
        this.difficulty = "medium";
        this.username = "Player";
        this.currentScore = 0;
        this.level = 1;
        this.highScore = 0;
    }

    /**
     * Konstruktor s parametry.
     */
    public GameConfig(String difficulty, String username, int currentScore, int level, int highScore) {
        this.difficulty = difficulty;
        this.username = username;
        this.currentScore = currentScore;
        this.level = level;
        this.highScore = highScore;
    }

    // Gettery a settery
    public String getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(String difficulty) {
        this.difficulty = difficulty;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public int getCurrentScore() {
        return currentScore;
    }

    public void setCurrentScore(int currentScore) {
        this.currentScore = currentScore;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public int getHighScore() {
        return highScore;
    }

    public void setHighScore(int highScore) {
        this.highScore = highScore;
    }

    @Override
    public String toString() {
        return "GameConfig{" +
                "difficulty='" + difficulty + '\'' +
                ", username='" + username + '\'' +
                ", currentScore=" + currentScore +
                ", level=" + level +
                ", highScore=" + highScore +
                '}';
    }
}
