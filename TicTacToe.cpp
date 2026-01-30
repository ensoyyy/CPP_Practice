#include <SFML/Graphics.hpp>
#include <iostream>

class TicTacToe{
    private:
        char board[3][3];
        
        bool checkLine(char player, int row1, int col1, int row2, int col2, int row3, int col3) const{
            return board[row1][col1] == player && board[row2][col2] == player && board[row3][col3] == player;
        }
    
    public:
        TicTacToe(){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    board[i][j] = ' ';
                }
            }
        }

        bool makeMove(int row, int col, char player){
            if(row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' '){
                return false;
            }
            board[row][col] = player;
            return true;
        }

        bool checkWin(char player) const{
            for(int i = 0; i < 3; ++i){
                if(checkLine(player, i, 0, i, 1, i, 2)) return true;
            }
            for(int j = 0; j < 3; ++j){
                if(checkLine(player, 0, j, 1, j, 2, j)) return true;
            }
            if(checkLine(player, 0, 0, 1, 1, 2, 2)) return true;
            if(checkLine(player, 0, 2, 1, 1, 2, 0)) return true;
            
            return false;
        }
        
        bool isBoardFull() const{
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(board[i][j] == ' ') return false;
                }
            }
            return true;
        }
        
        char getCell(int row, int col) const{
            return board[row][col];
        }
        
        void reset(){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    board[i][j] = ' ';
                }
            }
        }
};

int main(){
    sf::RenderWindow window(sf::VideoMode(600, 750), "Tic Tac Toe");
    window.setFramerateLimit(60);
    
    TicTacToe game;
    char currentPlayer = 'X';
    bool gameOver = false;
    std::string message = "Player X's turn";
    
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    
    sf::Text statusText(message, font, 20);
    statusText.setPosition(50, 620);
    statusText.setFillColor(sf::Color::Black);
    
    // Play Again Button
    sf::RectangleShape playAgainButton(sf::Vector2f(200, 50));
    playAgainButton.setPosition(200, 670);
    playAgainButton.setFillColor(sf::Color::Blue);
    
    sf::Text playAgainText("Play Again", font, 20);
    playAgainText.setPosition(225, 680);
    playAgainText.setFillColor(sf::Color::White);
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
                
            if(event.type == sf::Event::MouseButtonPressed && !gameOver){
                int col = event.mouseButton.x / 200;
                int row = event.mouseButton.y / 200;
                
                if(col >= 0 && col < 3 && row >= 0 && row < 3){
                    if(game.makeMove(row, col, currentPlayer)){
                        if(game.checkWin(currentPlayer)){
                            message = "Player " + std::string(1, currentPlayer) + " wins!";
                            gameOver = true;
                        } else if(game.isBoardFull()){
                            message = "It's a draw!";
                            gameOver = true;
                        } else {
                            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                            message = "Player " + std::string(1, currentPlayer) + "'s turn";
                        }
                    }
                }
            }
            
            // Play Again button click
            if(event.type == sf::Event::MouseButtonPressed && gameOver){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if(playAgainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
                    game.reset();
                    currentPlayer = 'X';
                    gameOver = false;
                    message = "Player X's turn";
                }
            }
        }
        
        window.clear(sf::Color::White);
        
        // Draw grid lines
        sf::RectangleShape hLine(sf::Vector2f(600, 3));
        sf::RectangleShape vLine(sf::Vector2f(3, 600));
        hLine.setFillColor(sf::Color::Black);
        vLine.setFillColor(sf::Color::Black);
        
        for(int i = 1; i < 3; ++i){
            hLine.setPosition(0, i * 200);
            window.draw(hLine);
            vLine.setPosition(i * 200, 0);
            window.draw(vLine);
        }
        
        // Draw X's and O's
        for(int row = 0; row < 3; ++row){
            for(int col = 0; col < 3; ++col){
                char cell = game.getCell(row, col);
                if(cell != ' '){
                    sf::Text cellText(std::string(1, cell), font, 80);
                    cellText.setPosition(col * 200 + 50, row * 200 + 30);
                    
                    if(cell == 'X')
                        cellText.setFillColor(sf::Color::Red);
                    else
                        cellText.setFillColor(sf::Color::Blue);
                    
                    window.draw(cellText);
                }
            }
        }
        
        statusText.setString(message);
        window.draw(statusText);
        
        // Draw Play Again button only when game is over
        if(gameOver){
            window.draw(playAgainButton);
            window.draw(playAgainText);
        }
        
        window.display();
    }
    
    return 0;
}