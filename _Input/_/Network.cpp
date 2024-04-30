#include"Network.hpp"

#include"Debug.hpp"

namespace NDespair
{
    CNetwork::CNetwork()
    {
        GNetwork = this;
        GDebug->AAssertSimpleDirectMediaLayerCode(SDLNet_Init());
        std::cout << "Server or Client? ";
        std::cin >> FMode;
        if(FMode == "Server")
        {
            GDebug->AAssertSimpleDirectMediaLayerCode(SDLNet_ResolveHost(&FAddress , nullptr , 8888));
            GDebug->AAssertSimpleDirectMediaLayerHandle(FSocket = SDLNet_TCP_Open(&FAddress));
            FClients.resize(1);
            FSets.resize(FClients.size());
            for(std::intmax_t LClient{0} ; LClient < static_cast<std::intmax_t>(FClients.size()) ; LClient++)
            {
                GDebug->AAssertSimpleDirectMediaLayerHandle(FSets[LClient] = SDLNet_AllocSocketSet(1));
                std::cout << "Waiting for clients to connect..." << "\n";
                while(!FClients[LClient])
                {
   	                FClients[LClient] = SDLNet_TCP_Accept(FSocket);
                }
                std::cout << "Clients connected successfully!" << "\n";
                GDebug->AAssertSimpleDirectMediaLayerCode(SDLNet_TCP_AddSocket(FSets[LClient] , FClients[LClient]));
            }
            return;
        }
        if(FMode == "Client")
        {
            std::cout << "Address to connect (wildcards like 'localhost' are also available): ";
            std::string LAddress;
            std::cin >> LAddress;
            GDebug->AAssertSimpleDirectMediaLayerCode(SDLNet_ResolveHost(&FAddress , LAddress.data() , 8888));
            std::cout << "Waiting for server to host..." << "\n";
            while(!FSocket)
            {
                FSocket = SDLNet_TCP_Open(&FAddress);
            }
            std::cout << "Server hosted successfully!" << "\n";
            return;
        }
    }
    std::string CNetwork::AMode()
    {
        return FMode;
    }
    void CNetwork::ASend(const std::string& PString)
    {
        for(std::intmax_t LClient{0} ; LClient < static_cast<std::intmax_t>(FClients.size()) ; LClient++)
        {
            std::intmax_t LSize{static_cast<std::intmax_t>(PString.size())};
            std::int32_t LSent;
            LSent = SDLNet_TCP_Send(FClients[LClient] , &LSize , static_cast<std::int32_t>(sizeof(LSize)));
            GDebug->AAssert(LSent != sizeof(LSize));
            LSent = SDLNet_TCP_Send(FClients[LClient], PString.data() , static_cast<std::int32_t>(PString.size()));
            GDebug->AAssert(LSent != PString.size());
        }
    }
    std::string CNetwork::AReceive()
    {
        std::string LString;
        std::intmax_t LSize;
        std::int32_t LReceived;
        LReceived = SDLNet_TCP_Recv(FSocket , &LSize , static_cast<std::int32_t>(sizeof(LSize)));
        GDebug->AAssert(LReceived != sizeof(LSize));
        LString.resize(LSize);
        LReceived = SDLNet_TCP_Recv(FSocket , LString.data() , static_cast<std::int32_t>(LString.size()));
        GDebug->AAssert(LReceived != LString.size());
        return LString;
    }
    CNetwork::~CNetwork()
    {
        if(FMode == "Server")
        {
            for(std::intmax_t LClient{0} ; LClient < static_cast<std::intmax_t>(FClients.size()) ; LClient++)
            {
                GDebug->AAssertSimpleDirectMediaLayerCode(SDLNet_TCP_DelSocket(FSets[LClient] , FClients[LClient]));
                SDLNet_TCP_Close(FClients[LClient]);
                SDLNet_FreeSocketSet(FSets[LClient]);
            }
        }
        SDLNet_TCP_Close(FSocket);
        SDLNet_Quit();
    }
}