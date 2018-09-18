// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.


#pragma once

#include <udpbox.h>
#include <SensorData.h>


namespace network {
struct Dispatcher
{
    static float dispatchFloat(const uint8_t* buffer)
    {
        return *reinterpret_cast<const float*>(buffer);
    }

    static sensorFusion::SensorData dispatch(udpbox::Datagram& datagram)
    {
        static const int offset = 16;
        return sensorFusion::SensorData{
            {
                dispatchFloat(&datagram.payload[offset+0]),
                dispatchFloat(&datagram.payload[offset+4]),
                dispatchFloat(&datagram.payload[offset+8]),
            },
            {
                dispatchFloat(&datagram.payload[offset+12]),
                dispatchFloat(&datagram.payload[offset+16]),
                dispatchFloat(&datagram.payload[offset+20]),
            },
            {
                dispatchFloat(&datagram.payload[offset+24]),
                dispatchFloat(&datagram.payload[offset+28]),
                dispatchFloat(&datagram.payload[offset+32]),
            },
        };
    }
};
}
