#!/vendor/bin/sh

# Copyright (c) 2018 The LineageOS Project
#
# Device configuration for lux variants
#
PATH=/sbin:/vendor/sbin:/vendor/bin:/vendor/xbin
export PATH

radio=`getprop ro.boot.radio`
carrier=`getprop ro.boot.carrier`
numsims=`getprop ro.boot.num-sims`

if [ $numsims -eq 2 ]
then
    carrier="msim"
fi

set_config_props ()
{
    case $radio in
        0x4 ) # XT1562
            case $carrier in
                msim )
                    setprop ro.device.dualsim true
                ;;
                retgb|reteu|retde|vfau )
                    setprop ro.device.dualsim false
                ;;
                * )
                    setprop ro.device.dualsim true
                ;;
            esac
        ;;
        0x8 ) # XT1563
            case $carrier in
                msim|retbr|retla|tefbr|timbr|retmx )
                    setprop ro.device.dualsim true
                ;;
                * )
                    setprop ro.device.dualsim false
                ;;
            esac
        ;;
    esac
}

# Main
set_config_props

return 0
