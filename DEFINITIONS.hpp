#pragma once

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define SPLASH_STATE_SHOW_TIME 2

#define SPLASH_SCENE_BACKGROUND_FILEPATH "./Assets/graphics/sky.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "./Assets/graphics/MainMenuBackground.png"
#define GAME_BACKGROUND_FILEPATH "./Assets/graphics/board.jpg"
#define PAUSE_BACKGROUND_FILEPATH "./Assets/graphics/MainMenuBackground.png"

#define MAIN_MENU_TITLE_PATH "./Assets/graphics/GameTitle.png"
#define MAIN_MENU_PLAY_BUTTON "./Assets/graphics/PlayButton.jpg"
#define MAIN_MENU_PLAY_BUTTON_OUTER "./Assets/graphics/PlayButtonBorder.png"

#define GAME_ROLL_BUTTON_FILEPATH "./Assets/graphics/RollButton.png"
#define GAME_SUGGEST_BUTTON_FILEPATH "./Assets/graphics/SuggestButton.png"
#define GAME_ACCUSE_BUTTON_FILEPATH "./Assets/graphics/AccuseButton.png"
#define GAME_END_TURN_BUTTON_FILEPATH "./Assets/graphics/EndTurnButton.png"
#define GAME_MY_CARDS_BUTTON_FILEPATH "./Assets/graphics/MyCardsButton.png"
#define GAME_NOTEBOOK_BUTTON_FILEPATH "./Assets/graphics/NotebookButton.png"

#define GRID_SPRITE_FILEPATH "./Assets/graphics/grid.png"
#define W_PIECE_FILEPATH "./Assets/graphics/wPiece.png"
#define B_PIECE_FILEPATH "./Assets/graphics/bPiece.png"
#define R_PIECE_FILEPATH "./Assets/graphics/rPiece.png"
#define Br_PIECE_FILEPATH "./Assets/graphics/brPiece.png"
#define G_PIECE_FILEPATH "./Assets/graphics/gPiece.png"
#define P_PIECE_FILEPATH "./Assets/graphics/pPiece.png"

#define GRID_CELL_SIZE 50
#define CELLS_X 12
#define CELLS_Y 12
#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95

enum GameStates {
	ePlaying,
	eTurnOver,
	eGameOver
};
