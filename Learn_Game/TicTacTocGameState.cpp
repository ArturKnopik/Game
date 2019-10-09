#include "TicTacTocGameState.h"
#include <iostream>
#include <cstdlib>
using namespace TicTacToc;
void TicTacTocGameState::initBoard()
{
	whoWin = WhoWin::STILL_PLAYING;
	gameBoard.clear();
	gameBoard.push_back(std::vector<Cell>());
	gameBoard[0].push_back(Cell(' ', sf::Vector2f(100,50), sf::Vector2f(195,195)));
	gameBoard[0].push_back(Cell(' ', sf::Vector2f(300, 50), sf::Vector2f(195, 195)));
	gameBoard[0].push_back(Cell(' ', sf::Vector2f(500, 50), sf::Vector2f(195, 195)));
	gameBoard.push_back(std::vector<Cell>());
	gameBoard[1].push_back(Cell(' ', sf::Vector2f(100, 250), sf::Vector2f(195, 195)));
	gameBoard[1].push_back(Cell(' ', sf::Vector2f(300, 250), sf::Vector2f(195, 195)));
	gameBoard[1].push_back(Cell(' ', sf::Vector2f(500, 250), sf::Vector2f(195, 195)));
	gameBoard.push_back(std::vector<Cell>());
	gameBoard[2].push_back(Cell(' ', sf::Vector2f(100, 450), sf::Vector2f(195, 195)));
	gameBoard[2].push_back(Cell(' ', sf::Vector2f(300, 450), sf::Vector2f(195, 195)));
	gameBoard[2].push_back(Cell(' ', sf::Vector2f(500, 450), sf::Vector2f(195, 195)));
	if (rand() % 2 == 1)
	{
		playerTurn = PlayerTurn::X_PLAYER;
		std::cout << "X_player" << std::endl;
	}
	else
	{
		playerTurn = PlayerTurn::O_PLAYER;
		std::cout << "O_player" << std::endl;
	}
}

TicTacTocGameState::TicTacTocGameState(std::shared_ptr<Game> game)
{
	event = std::make_shared<sf::Event>();
	this->game = game;
	texture.loadFromFile("resource/image/TicTacToe/O_X_TicTacToc.png");
	endScreenWhoWinTexture.loadFromFile("resource/image/TicTacToe/Win_Draw.png");
	endScreenWhoWin.setTexture(&endScreenWhoWinTexture);
	endScreenWhoWin.setPosition(800, 300);
	endScreenWhoWin.setSize(sf::Vector2f(400, 300));

	markedRect.setSize(sf::Vector2f(195, 195));
	intRect_X.left = 0;
	intRect_X.top = 27;
	intRect_X.width = 620;
	intRect_X.height = 620;
	intRect_O.left = 683;
	intRect_O.top = 0;
	intRect_O.width = 685;
	intRect_O.height = 679;
	markedRect.setTexture(&texture);

	initBoard();
}

void TicTacTocGameState::draw()
{
	std::vector<std::vector<Cell>>::iterator row;
	std::vector<Cell>::iterator col;
	for (row = gameBoard.begin(); row != gameBoard.end(); row++)
	{
		for (col = row->begin(); col != row->end(); col++)
		{
			sf::RectangleShape rect;
			if (playerTurn == PlayerTurn::O_PLAYER)
			{
				rect.setFillColor(sf::Color(100,100,150,150));
			}
			else
			{
				rect.setFillColor(sf::Color(150, 100, 100, 150));
			}


			if (whoWin != WhoWin::STILL_PLAYING)
			{
				if (whoWin == WhoWin::DRAW)
				{
					markedRect.setPosition(800, 100);
					markedRect.setTextureRect(sf::IntRect(0, 0, 1370, 679));

					endScreenWhoWin.setTextureRect(sf::IntRect(0, 0, 400, 300));
					game->window->draw(endScreenWhoWin);
					game->window->draw(markedRect);
					rect.setFillColor(sf::Color(100, 100, 100, 150));
				}
				else
				{
					endScreenWhoWin.setTextureRect(sf::IntRect(400, 0, 400, 300));
					markedRect.setPosition(900, 100);
					switch (whoWin)
					{
					case WhoWin::X_WIN:
						markedRect.setTextureRect(intRect_X);
						game->window->draw(markedRect);
						break;
					case WhoWin::O_WIN:
						markedRect.setTextureRect(intRect_O);
						game->window->draw(markedRect);
						break;
					}

					if (whoWin == WhoWin::X_WIN)
					{
						rect.setFillColor(sf::Color(150, 100, 100, 150));
						endScreenWhoWin.setFillColor(sf::Color(150, 50, 50, 255));
					}
					else if (whoWin == WhoWin::O_WIN)
					{
						endScreenWhoWin.setFillColor(sf::Color(50, 50, 150, 255));
						rect.setFillColor(sf::Color(100, 100, 150, 150));
					}
					game->window->draw(endScreenWhoWin);
				}
			}

			game->window->draw(rect);
			rect.setPosition(col->getPosition().x, col->getPosition().y);
			rect.setSize(sf::Vector2f(col->getSize().x, col->getSize().y));
			game->window->draw(rect);
			switch (col->getSymbol())
			{
			case 'x':
				markedRect.setPosition(col->getPosition().x, col->getPosition().y);
				markedRect.setTextureRect(intRect_X);
				game->window->draw(markedRect);
				break;
			case 'o':
				markedRect.setPosition(col->getPosition().x, col->getPosition().y);
				markedRect.setTextureRect(intRect_O);
				game->window->draw(markedRect);
				break;
			}
		}
	}
}

void TicTacTocGameState::update(const double dt)
{
	std::vector<std::vector<Cell>>::iterator row;
	std::vector<Cell>::iterator col;
	markedCell = 0;
	for (row = gameBoard.begin(); row != gameBoard.end(); row++)
	{
		for (col = row->begin(); col != row->end(); col++)
		{
			if (col->getSymbol() != ' ')
			{
				markedCell++;
			}
		}
	}

	if (markedCell == 9 && ((whoWin!=WhoWin::O_WIN && whoWin != WhoWin::X_WIN)))
	{
		whoWin=WhoWin::DRAW;
		endScreenWhoWin.setFillColor(sf::Color(200, 200, 200));
	}
}

void TicTacTocGameState::input()
{
	while (game->window->pollEvent(*event)) {
		switch (event->type) {
		case sf::Event::Closed:
			game->window->close();
			break;
		case sf::Event::KeyPressed:
			if (event->key.code == sf::Keyboard::Escape) {
				game->popState();
			}
			if (event->key.code == sf::Keyboard::R) {
				initBoard();
			}
		break;
		case sf::Event::MouseButtonPressed:
			if (whoWin == STILL_PLAYING)
			{
				if (event->mouseButton.button == sf::Mouse::Left)
				{
					checkCellClick(sf::Vector2f(sf::Mouse::getPosition((*game->window))));
					checkWhoWin();
				}
			}
			break;
		}
	}
}

void TicTacTocGameState::checkCellClick(sf::Vector2f mousePos)
{
	std::vector<std::vector<Cell>>::iterator row;
	std::vector<Cell>::iterator col;
	for (row = gameBoard.begin(); row != gameBoard.end(); row++)
	{
		for (col = row->begin(); col != row->end(); col++)
		{
			if (col->getPosition().x < mousePos.x && (col->getPosition().x + col->getSize().x) > mousePos.x &&
				col->getPosition().y < mousePos.y && col->getPosition().y + col->getSize().y > mousePos.y)
			{
				if (col->getSymbol() == ' ')
				{
					if (playerTurn == PlayerTurn::X_PLAYER)
					{
						col->markCell('x');
						playerTurn = PlayerTurn::O_PLAYER;
					}
					else
					{
						col->markCell('o');
						playerTurn = PlayerTurn::X_PLAYER;
					}
				}
			}
		}
	}
}

void TicTacTocGameState::checkWhoWin()
{

	if ((gameBoard[0][0].getSymbol() == gameBoard[0][1].getSymbol()) && (gameBoard[0][1].getSymbol() == gameBoard[0][2].getSymbol()))
	{
		if (gameBoard[0][0].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[0][0].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}	
	//000
	//...
	//...

	if ((gameBoard[1][0].getSymbol() == gameBoard[1][1].getSymbol()) && (gameBoard[1][1].getSymbol() == gameBoard[1][2].getSymbol()))
	{
		if (gameBoard[1][0].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[1][0].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//...
	//000
	//...
	
	if ((gameBoard[2][0].getSymbol() == gameBoard[2][1].getSymbol()) && (gameBoard[2][1].getSymbol() == gameBoard[2][2].getSymbol()))
	{
		if (gameBoard[2][0].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[2][0].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//...
	//...
	//000


	if ((gameBoard[0][0].getSymbol() == gameBoard[1][1].getSymbol()) && (gameBoard[1][1].getSymbol() == gameBoard[2][2].getSymbol()))
	{
		if (gameBoard[0][0].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[0][0].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//0..
	//.0.
	//..0

	if ((gameBoard[0][2].getSymbol() == gameBoard[1][1].getSymbol()) && (gameBoard[1][1].getSymbol() == gameBoard[2][0].getSymbol()))
	{
		if (gameBoard[0][2].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[0][2].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//..0
	//.0.
	//0..

	if ((gameBoard[0][0].getSymbol() == gameBoard[1][0].getSymbol()) && (gameBoard[1][0].getSymbol() == gameBoard[2][0].getSymbol()))
	{
		if (gameBoard[0][0].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[0][0].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//0..
	//0..
	//0..

	if ((gameBoard[0][1].getSymbol() == gameBoard[1][1].getSymbol()) && (gameBoard[1][1].getSymbol() == gameBoard[2][1].getSymbol()))
	{
		if (gameBoard[0][1].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[0][1].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//.0.
	//.0.
	//.0.

	if ((gameBoard[0][2].getSymbol() == gameBoard[1][2].getSymbol()) && (gameBoard[1][2].getSymbol() == gameBoard[2][2].getSymbol()))
	{
		if (gameBoard[0][2].getSymbol() == 'x')
		{
			whoWin = WhoWin::X_WIN;
		}
		else if (gameBoard[0][2].getSymbol() == 'o')
		{
			whoWin = WhoWin::O_WIN;
		}
	}
	//..0
	//..0
	//..0
}

