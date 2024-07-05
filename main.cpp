#include <iostream>
#include <vector>
#include <windows.h>    // Include Windows headers
#include <PCANBasic.h>  // Include PCANBasic header

std::vector<TPCANHandle> getConnectedPcanDevices()
{
    std::vector<TPCANHandle> deviceHandles;
    TPCANChannelInformation channelInfo[64];  // Array to store channel information
    DWORD channelCount = 64;                  // Maximum number of channels we can retrieve
    TPCANStatus status = CAN_GetValue(PCAN_NONEBUS, PCAN_ATTACHED_CHANNELS, channelInfo, sizeof(channelInfo));

    if (status == PCAN_ERROR_OK)
    {
        for (DWORD i = 0; i < channelCount; ++i)
        {
            if (channelInfo[i].channel_handle != PCAN_NONEBUS && channelInfo[i].channel_handle != 0xcccc)
            {
                deviceHandles.push_back(channelInfo[i].channel_handle);
            }
        }
    }
    else
    {
        std::cout << "Error retrieving channels: " << status << std::endl;
    }

    return deviceHandles;
}

int main()
{
    std::vector<TPCANHandle> connectedDevices = getConnectedPcanDevices();

    if (!connectedDevices.empty())
    {
        std::cout << "Connected PCAN devices:" << std::endl;
        for (const auto& handle : connectedDevices)
        {
            std::cout << "Device Handle: " << handle << std::endl;
        }
    }
    else
    {
        std::cout << "No PCAN devices connected." << std::endl;
    }

    return 0;
}
