

#include "inputdevicelist.h"

bool InputDevice::operator ==(const InputDevice &device)
{
    return this->deviceType == device.deviceType && this->interface == device.interface;
}

QDBusArgument &operator<<(QDBusArgument &argument, const InputDevice &device)
{
    argument.beginStructure();
    argument << device.interface << device.deviceType;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, InputDevice &device)
{
    argument.beginStructure();
    argument >> device.interface >> device.deviceType;
    argument.endStructure();
    return argument;
}

void registerInputDeviceListMetaType()
{
    qRegisterMetaType<InputDeviceList>("InputDeviceList");
    qDBusRegisterMetaType<InputDeviceList>();
}
