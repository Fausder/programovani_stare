package cz.uhk.ladybug;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Správce pro načítání a ukládání konfigurace do JSON souboru.
 */
public class ConfigManager {
    private static final String CONFIG_FILE = "config.json";
    private final Gson gson;

    public ConfigManager() {
        this.gson = new GsonBuilder().setPrettyPrinting().create();
    }

    /**
     * Načte konfiguraci ze souboru.
     * Pokud soubor neexistuje nebo je chybný, vytvoří nový s výchozími hodnotami.
     */
    public GameConfig loadConfig() {
        try {
            File configFile = new File(CONFIG_FILE);
            
            // Pokud soubor neexistuje, vytvoříme ho s výchozími hodnotami
            if (!configFile.exists()) {
                System.out.println("Konfigurační soubor nenalezen. Vytváření s výchozími hodnotami...");
                GameConfig defaultConfig = new GameConfig();
                saveConfig(defaultConfig);
                return defaultConfig;
            }

            // Načtení konfigurace ze souboru
            String json = new String(Files.readAllBytes(Paths.get(CONFIG_FILE)));
            GameConfig config = gson.fromJson(json, GameConfig.class);
            
            // Validace načtené konfigurace
            if (config == null) {
                System.err.println("Chyba při parsování konfigurace. Použity výchozí hodnoty.");
                return new GameConfig();
            }
            
            System.out.println("Konfigurace načtena: " + config);
            return config;
            
        } catch (IOException e) {
            System.err.println("Chyba při načítání konfigurace: " + e.getMessage());
            return new GameConfig();
        } catch (Exception e) {
            System.err.println("Neočekávaná chyba při načítání konfigurace: " + e.getMessage());
            return new GameConfig();
        }
    }

    /**
     * Uloží konfiguraci do souboru.
     */
    public boolean saveConfig(GameConfig config) {
        try {
            String json = gson.toJson(config);
            
            try (FileWriter writer = new FileWriter(CONFIG_FILE)) {
                writer.write(json);
                writer.flush();
            }
            
            System.out.println("Konfigurace uložena: " + config);
            return true;
            
        } catch (IOException e) {
            System.err.println("Chyba při ukládání konfigurace: " + e.getMessage());
            return false;
        } catch (Exception e) {
            System.err.println("Neočekávaná chyba při ukládání konfigurace: " + e.getMessage());
            return false;
        }
    }

    /**
     * Aktualizuje konkrétní hodnotu v konfiguraci a uloží ji.
     */
    public boolean updateConfig(String key, Object value) {
        try {
            GameConfig config = loadConfig();
            
            switch (key.toLowerCase()) {
                case "difficulty":
                    config.setDifficulty((String) value);
                    break;
                case "username":
                    config.setUsername((String) value);
                    break;
                case "currentscore":
                    config.setCurrentScore((Integer) value);
                    break;
                case "level":
                    config.setLevel((Integer) value);
                    break;
                case "highscore":
                    config.setHighScore((Integer) value);
                    break;
                default:
                    System.err.println("Neznámý konfigurační klíč: " + key);
                    return false;
            }
            
            return saveConfig(config);
            
        } catch (Exception e) {
            System.err.println("Chyba při aktualizaci konfigurace: " + e.getMessage());
            return false;
        }
    }
}
