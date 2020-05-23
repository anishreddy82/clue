#pragma once

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define SPLASH_STATE_SHOW_TIME 2

#define BUTTON_SCALE .08

#define SPLASH_SCENE_BACKGROUND_FILEPATH "./Assets/graphics/sky.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "./Assets/graphics/MainMenuBackground.png"
#define GAME_BACKGROUND_FILEPATH "./Assets/graphics/board.jpg"
#define PAUSE_BACKGROUND_FILEPATH "./Assets/graphics/MainMenuBackground.png"

#define MAIN_MENU_TITLE_PATH "./Assets/graphics/GameTitle.png"
#define MAIN_MENU_PLAY_BUTTON "./Assets/graphics/PlayButton.jpg"
#define MAIN_MENU_PLAY_BUTTON_OUTER "./Assets/graphics/PlayButtonBorder.png"

#define NEXT_GRAYED_FILEPATH "./Assets/graphics/NextGrayed.png"
#define NEXT_ACTIVE_FILEPATH "./Assets/graphics/NextButton.png"
#define INC_BUTTON_FILEPATH "./Assets/graphics/IncButton.png"
#define DEC_BUTTON_FILEPATH "./Assets/graphics/DecButton.png"
#define CONFIRM_BUTTON_FILEPATH "./Assets/graphics/ConfirmButton.png"
#define SET_BUTTON_FILEPATH "./Assets/graphics/SetPlayers.png"

#define GAME_ROLL_BUTTON_FILEPATH "./Assets/graphics/RollButton.png"
#define GAME_SUGGEST_BUTTON_FILEPATH "./Assets/graphics/SuggestButton.png"
#define GAME_ACCUSE_BUTTON_FILEPATH "./Assets/graphics/AccuseButton.png"
#define GAME_END_TURN_BUTTON_FILEPATH "./Assets/graphics/EndTurnButton.png"
#define GAME_MY_CARDS_BUTTON_FILEPATH "./Assets/graphics/MyCardsButton.png"
#define GAME_NOTEBOOK_BUTTON_FILEPATH "./Assets/graphics/NotebookButton.png"

#define CHECK_BUTTON_FILEPATH "./Assets/graphics/checkButton.png"
#define CROSS_BUTTON_FILEPATH "./Assets/graphics/crossButton.png"

#define GRID_SPRITE_FILEPATH "./Assets/graphics/grid.png"
#define W_PIECE_FILEPATH "./Assets/graphics/wPiece.png"
#define B_PIECE_FILEPATH "./Assets/graphics/bPiece.png"
#define R_PIECE_FILEPATH "./Assets/graphics/rPiece.png"
#define Br_PIECE_FILEPATH "./Assets/graphics/brPiece.png"
#define G_PIECE_FILEPATH "./Assets/graphics/gPiece.png"
#define P_PIECE_FILEPATH "./Assets/graphics/pPiece.png"

#define CSTICK_FILEPATH "./Assets/graphics/candlestick.png"
#define KNIFE_FILEPATH "./Assets/graphics/knife.png"
#define PIPE_FILEPATH "./Assets/graphics/pipe.png"
#define GUN_FILEPATH "./Assets/graphics/revolver.png"
#define ROPE_FILEPATH "./Assets/graphics/rope.png"
#define WRENCH_FILEPATH "./Assets/graphics/wrench.png"


/*
Cards Assests
*/
#define BLUE_CARD_FILEPATH "./Assets/graphics/cards/blueCard.png"
#define BROWN_CARD_FILEPATH "./Assets/graphics/cards/brownCard.png"
#define GREEN_CARD_FILEPATH "./Assets/graphics/cards/greenCard.png"
#define PURPLE_CARD_FILEPATH "./Assets/graphics/cards/purpleCard.png"
#define RED_CARD_FILEPATH "./Assets/graphics/cards/redCard.png"
#define WHITE_CARD_FILEPATH "./Assets/graphics/cards/whiteCard.png"
#define YELLOW_CARD_FILEPATH "./Assets/graphics/cards/yellowCard.png"

#define BALLROOM_CARD_FILEPATH "./Assets/graphics/cards/ballroomCard.png"
#define BILLARD_CARD_FILEPATH "./Assets/graphics/cards/billardCard.png"
#define CONSERVATORY_CARD_FILEPATH "./Assets/graphics/cards/conservatoryCard.png"
#define DINING_CARD_FILEPATH "./Assets/graphics/cards/diningCard.png"
#define HALL_CARD_FILEPATH "./Assets/graphics/cards/hallCard.png"
#define KITCHEN_CARD_FILEPATH "./Assets/graphics/cards/kitchenCard.png"
#define LIBRARY_CARD_FILEPATH "./Assets/graphics/cards/libraryCard.png"
#define LOUNGE_CARD_FILEPATH "./Assets/graphics/cards/loungeCard.png"
#define STUDY_CARD_FILEPATH "./Assets/graphics/cards/studyCard.png"

#define CANDLESTICK_CARD_FILEPATH "./Assets/graphics/cards/candlestickCard.png"
#define KNIFE_CARD_FILEPATH "./Assets/graphics/cards/knifeCard.png"
#define LEADPIPE_CARD_FILEPATH "./Assets/graphics/cards/leadpipeCard.png"
#define REVOLVER_CARD_FILEPATH "./Assets/graphics/cards/revolverCard.png"
#define ROPE_CARD_FILEPATH "./Assets/graphics/cards/ropeCard.png"
#define WRENCH_CARD_FILEPATH "./Assets/graphics/cards/wrenchCard.png"

/*
HandOfCardsState Assests
*/
#define RETURN_BUTTON_FILEPATH "./Assets/graphics/returnButton.png"
#define CARDS_BACKGROUND_FILEPATH "./Assets/graphics/secretBackground.jpg"


#define ROLL_FONT_FILEPATH "./Assets/fonts/arial.ttf"

#define GRID_CELL_SIZE 50
#define CELLS_X 12
#define CELLS_Y 12

#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define MOVE_UP 3
#define MOVE_DOWN 4

enum GameStates {
	ePlaying,
	eTurnOver,
	ePaused,
	eGameOver
};

enum Locations {
	eHallway,
	eStudy,
	eHall,
	eLounge,
	eLibrary,
	eDining,
	eBilliards,
	eBall,
	eConservatory,
	eKitchen
};
