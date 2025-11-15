package cz.uhk.ladybug;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * Hlavní aplikace Ladybug hry.
 */
public class LadyBugApp extends Application {
    private static ConfigManager configManager;
    private static ScoreManager scoreManager;

    @Override
    public void start(Stage primaryStage) {
        try {
            // Inicializace manažerů
            configManager = new ConfigManager();
            scoreManager = new ScoreManager(configManager);

            // Načtení FXML souboru
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/main-menu.fxml"));
            VBox root = loader.load();

            // Nastavení kontroléru
            MainMenuController controller = loader.getController();
            controller.setManagers(configManager, scoreManager);

            // Vytvoření scény
            Scene scene = new Scene(root, 600, 400);
            primaryStage.setTitle("Ladybug Game");
            primaryStage.setScene(scene);
            primaryStage.show();

            System.out.println("Aplikace spuštěna úspěšně.");

        } catch (IOException e) {
            System.err.println("Chyba při načítání FXML: " + e.getMessage());
            e.printStackTrace();
        } catch (Exception e) {
            System.err.println("Neočekávaná chyba při spuštění aplikace: " + e.getMessage());
            e.printStackTrace();
        }
    }

    @Override
    public void stop() {
        // Uložení konfigurace při ukončení aplikace
        if (configManager != null && scoreManager != null) {
            configManager.saveConfig(scoreManager.getCurrentConfig());
            System.out.println("Konfigurace uložena při ukončení aplikace.");
        }
    }

    public static ConfigManager getConfigManager() {
        return configManager;
    }

    public static ScoreManager getScoreManager() {
        return scoreManager;
    }

    public static void main(String[] args) {
        launch(args);
    }
}
