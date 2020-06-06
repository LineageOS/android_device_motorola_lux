# Audio
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.audio.fluence.mode=endfire \
    persist.vendor.audio.fluence.voicecall=true \
    ro.vendor.audio.sdk.fluencetype=fluence

# Display
PRODUCT_PROPERTY_OVERRIDES += \
    debug.hwui.use_buffer_age=false \
    ro.sf.lcd_density=480

# Radio
PRODUCT_PROPERTY_OVERRIDES += \
    persist.radio.mot_ecc_enabled=1 \
    ro.gsm.data_retry_config="default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000"

