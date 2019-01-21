#pragma once
#include "GameState.h"
#include "TicTacToc_Cell.h"
namespace TicTacToc
{
	class TicTacTocGameState :
		public GameState
	{
	private:
		enum PlayerTurn
		{
			X_PLAYER,
			O_PLAYER
		};
		enum WhoWin
		{
			STILL_PLAYING,
			DRAW,
			X_WIN,
			O_WIN
		};
		WhoWin whoWin = WhoWin::STILL_PLAYING;
		sf::RectangleShape endScreenWhoWin;
		sf::Texture endScreenWhoWinTexture;
		PlayerTurn playerTurn;
		std::shared_ptr<sf::Event> event;
		std::vector<std::vector<Cell>> gameBoard;
		void initBoard();
		sf::Texture texture;
		sf::IntRect intRect_X;
		sf::IntRect intRect_O;
		sf::RectangleShape markedRect;
		bool win = false;
		int markedCell;
		void checkCellClick(sf::Vector2f mousePosition);
		void checkWhoWin();
	public:
		TicTacTocGameState() = delete;
		TicTacTocGameState(std::shared_ptr<Game> game);
		void draw();
		void update(const float dt);
		void input();
		virtual ~TicTacTocGameState() = default;
	};
}
