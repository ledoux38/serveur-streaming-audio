#include "utils.h"

#include <iomanip>
#include <math.h>


void progressBar(float prct, float buffer) {
    std::cout << '[';

    int width = getTermSize().x - 2;
    for(int i = 0; i < width; ++i) {
        if(i < prct*width)
            std::cout << "#";
        else if(i < buffer*width)
            std::cout << "-";
        else
            std::cout << " ";
    }

    std::cout << ']';
}

std::ostream& operator <<(std::ostream& os, const sf::Time& time) {
    int min = time.asSeconds()/60,
            sec = ((int)time.asSeconds())%60,
            milli = fmod(time.asMilliseconds(), 1000);

    os	<< std::setw(2) << std::setfill(' ') << min << ":"
        << std::setw(2) << std::setfill('0') << sec << "."
        << std::setw(3) << std::setfill('0') << milli;

    return os;
}

std::ostream& operator <<(std::ostream& os, const sf::Socket::Status& status) {
    switch(status) {
    case sf::Socket::NotReady:		os << "Socket not ready" << std::endl; break;
    case sf::Socket::Disconnected:
        os << "Socket disconnected" << std::endl;
        break;
    case sf::Socket::Error:			os << "Socket Error" << std::endl; break;
    case sf::Socket::Partial:		os << "Socket Parial result" << std::endl; break;
    case sf::Socket::Done:			break;
    }

    return os;
}



std::ostream& operator <<(std::ostream& os, const Packet::pckType& status)
{
    switch(status)
    {
    case Packet::pckType::CurrPlay:		    os << "CurrPlay"       << std::endl; break;
    case Packet::pckType::NewConnection:    os << "NewConnection"  << std::endl; break;
    case Packet::pckType::Ping:			    os << "Ping"           << std::endl; break;
    case Packet::pckType::Playlist:         os << "Playlist"       << std::endl; break;
    case Packet::pckType::Pong:			    os << "Pong"           << std::endl; break;
    case Packet::pckType::initialization:   os << "initialisation" << std::endl; break;
    }

    return os;
}




sf::Socket::Status log(sf::Socket::Status status) {
    operator <<(std::cout, status);

    return status;
}

sf::Packet& operator <<(sf::Packet& pck, const sf::Time& time) {
    return pck << time.asMicroseconds();
}

sf::Packet& operator >>(sf::Packet& pck, sf::Time &time) {
    sf::Int64 microSec;
    pck >> microSec;
    time = sf::microseconds(microSec);

    return pck;
}

#if defined(SFML_SYSTEM_WINDOWS)

#include <windows.h>

void resetPos() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
}

size getTermSize() {
    size out;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi );

    out.x = csbi.srWindow.Right - csbi.srWindow.Left +1;
    out.y = csbi.srWindow.Bottom - csbi.srWindow.Top +1;

    return out;
}

void clear() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.

    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.

    if( !FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
                                     dwConSize, {0, 0}, &cCharsWritten ))
        return;

    // Get the current text attribute.

    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return;

    // Set the buffer's attributes accordingly.

    if( !FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
                                     dwConSize, {0, 0}, &cCharsWritten ))
        return;

    // Put the cursor at its home coordinates.
    resetPos();
}

#elif defined(SFML_SYSTEM_LINUX)

#include <sys/ioctl.h>
#include <unistd.h>

//#warning Improve clear function
void clear() {
    //system("clear");
    //#warning UGLY !!!

    //Try this :
    std::cout << "\033[2J\033[1;1H";
}

size getTermSize() {
    size out;
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    out.x = w.ws_col;
    out.y = w.ws_row;

    return out;
}

#else
// Unsupported system
#error This operating system is not supported

#endif

#include <cstring>
Packet::Packet(pckType type) : type(type) {
        *this << (sf::Uint8)this->type;
}


const void* Packet::onSend(std::size_t& size) {
    data.resize(this->getDataSize() + sizeof(sf::Uint8));

    data[0] = (char)this->type;
    std::memcpy(&data[sizeof(sf::Uint8)], this->getData(), this->getDataSize());

    size = data.size();
    return &data[0];
}

void Packet::onReceive(const void* data, std::size_t size) {
    this->append(data + sizeof(sf::Uint8), size);

    sf::Uint8 tmp;
    *this >> tmp;

    this->type = (pckType)tmp;
}

