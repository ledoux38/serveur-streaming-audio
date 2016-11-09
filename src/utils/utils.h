#ifndef UTILS_H
#define UTILS_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <iostream>

#define PORT 54321

struct size {int x, y; };
size getTermSize();
void resetPos();
void clear();


std::ostream& operator <<(std::ostream& os, const sf::Time& time);
std::ostream& operator <<(std::ostream& os, const sf::Socket::Status& status);
sf::Socket::Status log(sf::Socket::Status status);

sf::Packet& operator <<(sf::Packet& pck, const sf::Time& time);
sf::Packet& operator >>(sf::Packet& pck, sf::Time& time);



void progressBar(float prct, float buffer = 0);

class Packet : public sf::Packet {
public:
    enum class pckType : sf::Int8
    {
        NewConnection =0,
        RawData = 1,
        Playlist = 2,
        CurrPlay = 3,
        Ping = 4,
        Pong = 5,
        initialization = 6,
    } type;

    Packet(pckType type = pckType::Ping);
    //	pckType type;

private:
    std::vector<char> data;

protected:
    virtual const void* onSend(std::size_t& size);
    virtual void onReceive(const void* data, std::size_t size);
};


template<class T, size_t S> sf::Packet& operator <<(sf::Packet& pck, const std::array<T, S>& arr) {
    for(T i : arr)
        pck << i;
    //    for(int i(0);i<S;++i)
    //    {
    //        pck<<arr[i];
    //    }

    return pck;
}
template<class T, size_t S> sf::Packet& operator >>(sf::Packet& pck, std::array<T, S>& arr) {

    //    for(int i = 0; i < S; ++i) {
    //        pck >> arr[i];

    //    }
    T tmp;
    for(int i = 0; i < S; ++i) {
        pck >> tmp;
        arr[i] = tmp;
    }
    return pck;
}

template<class T> sf::Packet& operator <<(sf::Packet& pck, const std::vector<T>& arr)
{
    int taille(arr.size());
    pck<<taille;
        for(int i(0);i<arr.size();++i)
        {
            pck<<arr[i];
        }

    return pck;
}

template<class T> sf::Packet& operator >>(sf::Packet& pck, std::vector<T>& arr)
{

    T tmp;
    int taille;
    pck>>taille;
    for(int i = 0; i <taille; ++i)
    {
        pck >> tmp;
        arr.push_back(tmp);
    }
    return pck;
}



#endif // UTILS_H
