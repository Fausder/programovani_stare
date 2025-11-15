package cz.uhk.ladybug;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

/**
 * Kontrolér pro hlavní menu hry.
 */
public class MainMenuController {
    @FXML
    private Label welcomeLabel;
    
    @FXML
    private Label currentScoreLabel;
    
    @FXML
    private Label highScoreLabel;
    
    @FXML
    private Label levelLabel;
    
    @FXML
    private TextField usernameField;
    
    @FXML
    private ComboBox<String> difficultyComboBox;
    
    @FXML
    private Button startButton;
    
    @FXML
    private Button addPointsButton;
    
    @FXML
    private Button resetButton;
    
    @FXML
    private Button saveButton;

    private ConfigManager configManager;
    private ScoreManager scoreManager;

    /**
     * Inicializace kontroléru.
     */
    @FXML
    public void initialize() {
        // Nastavení možností obtížnosti
        if (difficultyComboBox != null) {
            difficultyComboBox.getItems().addAll("easy", "medium", "hard");
        }
    }

    /**
     * Nastavení manažerů a aktualizace UI.
     */
    public void setManagers(ConfigManager configManager, ScoreManager scoreManager) {
        this.configManager = configManager;
        this.scoreManager = scoreManager;
        
        // Načtení konfigurace a aktualizace UI
        updateUI();
    }

    /**
     * Aktualizuje UI podle aktuální konfigurace.
     */
    private void updateUI() {
        if (scoreManager != null) {
            GameConfig config = scoreManager.getCurrentConfig();
            
            if (welcomeLabel != null) {
                welcomeLabel.setText("Vítejte, " + config.getUsername() + "!");
            }
            
            if (currentScoreLabel != null) {
                currentScoreLabel.setText("Aktuální skóre: " + config.getCurrentScore());
            }
            
            if (highScoreLabel != null) {
                highScoreLabel.setText("Nejvyšší skóre: " + config.getHighScore());
            }
            
            if (levelLabel != null) {
                levelLabel.setText("Úroveň: " + config.getLevel());
            }
            
            if (usernameField != null) {
                usernameField.setText(config.getUsername());
            }
            
            if (difficultyComboBox != null) {
                difficultyComboBox.setValue(config.getDifficulty());
            }
        }
    }

    /**
     * Handler pro tlačítko Start.
     */
    @FXML
    private void handleStart() {
        System.out.println("Hra spuštěna!");
        scoreManager.resetCurrentScore();
        updateUI();
    }

    /**
     * Handler pro přidání bodů (testovací funkce).
     */
    @FXML
    private void handleAddPoints() {
        scoreManager.addScore(100);
        updateUI();
        System.out.println("Přidáno 100 bodů.");
    }

    /**
     * Handler pro reset skóre.
     */
    @FXML
    private void handleReset() {
        scoreManager.resetCurrentScore();
        updateUI();
        System.out.println("Skóre resetováno.");
    }

    /**
     * Handler pro uložení nastavení.
     */
    @FXML
    private void handleSave() {
        if (usernameField != null && !usernameField.getText().isEmpty()) {
            configManager.updateConfig("username", usernameField.getText());
        }
        
        if (difficultyComboBox != null && difficultyComboBox.getValue() != null) {
            configManager.updateConfig("difficulty", difficultyComboBox.getValue());
        }
        
        scoreManager.reloadConfig();
        updateUI();
        System.out.println("Nastavení uloženo.");
    }
}
