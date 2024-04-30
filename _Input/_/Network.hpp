#pragma once

#include"Despair.hpp"

namespace NDespair
{
    inline class CNetwork
    {
        private : std::string FMode;
        private : IPaddress FAddress;
        private : TCPsocket FSocket;
        private : std::vector<TCPsocket> FClients;
        private : std::vector<SDLNet_SocketSet> FSets;
        
        public : CNetwork();
        public : std::string AMode();
        public : void ASend(const std::string& PString);
        public : std::string AReceive();
        public : ~CNetwork();
    }
    *GNetwork;
}