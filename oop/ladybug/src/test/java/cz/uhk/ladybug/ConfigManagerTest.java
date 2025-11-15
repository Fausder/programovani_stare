package cz.uhk.ladybug;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.File;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Testy pro ConfigManager a ScoreManager.
 */
class ConfigManagerTest {
    private ConfigManager configManager;
    private ScoreManager scoreManager;
    private static final String TEST_CONFIG_FILE = "config.json";

    @BeforeEach
    void setUp() {
        // Smazání testovacího souboru před testem
        File file = new File(TEST_CONFIG_FILE);
        if (file.exists()) {
            file.delete();
        }
        
        configManager = new ConfigManager();
        scoreManager = new ScoreManager(configManager);
    }

    @AfterEach
    void tearDown() {
        // Smazání testovacího souboru po testu
        File file = new File(TEST_CONFIG_FILE);
        if (file.exists()) {
            file.delete();
        }
    }

    @Test
    void testDefaultConfig() {
        GameConfig config = configManager.loadConfig();
        assertNotNull(config);
        assertEquals("medium", config.getDifficulty());
        assertEquals("Player", config.getUsername());
        assertEquals(0, config.getCurrentScore());
        assertEquals(1, config.getLevel());
        assertEquals(0, config.getHighScore());
    }

    @Test
    void testSaveAndLoadConfig() {
        GameConfig config = new GameConfig("hard", "TestUser", 100, 5, 150);
        assertTrue(configManager.saveConfig(config));
        
        GameConfig loadedConfig = configManager.loadConfig();
        assertNotNull(loadedConfig);
        assertEquals("hard", loadedConfig.getDifficulty());
        assertEquals("TestUser", loadedConfig.getUsername());
        assertEquals(100, loadedConfig.getCurrentScore());
        assertEquals(5, loadedConfig.getLevel());
        assertEquals(150, loadedConfig.getHighScore());
    }

    @Test
    void testUpdateConfig() {
        configManager.loadConfig(); // Vytvoření defaultního config
        
        assertTrue(configManager.updateConfig("username", "NewUser"));
        
        GameConfig config = configManager.loadConfig();
        assertEquals("NewUser", config.getUsername());
    }

    @Test
    void testScoreManagerAddScore() {
        scoreManager.addScore(50);
        assertEquals(50, scoreManager.getCurrentScore());
        assertEquals(50, scoreManager.getHighScore());
        
        scoreManager.addScore(30);
        assertEquals(80, scoreManager.getCurrentScore());
        assertEquals(80, scoreManager.getHighScore());
    }

    @Test
    void testScoreManagerHighScore() {
        scoreManager.addScore(100);
        assertEquals(100, scoreManager.getHighScore());
        
        scoreManager.resetCurrentScore();
        assertEquals(0, scoreManager.getCurrentScore());
        assertEquals(100, scoreManager.getHighScore()); // High score zůstává
        
        scoreManager.addScore(50);
        assertEquals(50, scoreManager.getCurrentScore());
        assertEquals(100, scoreManager.getHighScore()); // High score se nemění
        
        scoreManager.addScore(60);
        assertEquals(110, scoreManager.getCurrentScore());
        assertEquals(110, scoreManager.getHighScore()); // High score aktualizováno
    }

    @Test
    void testScoreManagerLevel() {
        assertEquals(1, scoreManager.getLevel());
        
        scoreManager.setLevel(3);
        assertEquals(3, scoreManager.getLevel());
    }

    @Test
    void testScoreManagerReset() {
        scoreManager.addScore(100);
        scoreManager.setLevel(5);
        
        scoreManager.resetCurrentScore();
        
        assertEquals(0, scoreManager.getCurrentScore());
        assertEquals(1, scoreManager.getLevel());
        assertEquals(100, scoreManager.getHighScore()); // High score zůstává
    }

    @Test
    void testConfigFileCreation() {
        configManager.loadConfig();
        
        File file = new File(TEST_CONFIG_FILE);
        assertTrue(file.exists());
    }
}
