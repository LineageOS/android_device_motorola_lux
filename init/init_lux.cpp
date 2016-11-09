/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

static void dual_sim(void);
static void single_sim(void);

void vendor_load_properties()
{
    bool force_msim = false;

    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string radio = property_get("ro.boot.radio");
    std::string sku = property_get("ro.boot.hardware.sku");
    std::string carrier = property_get("ro.boot.carrier");
    std::string numsims = property_get("ro.boot.num-sims");

    property_set("ro.product.model", sku.c_str());

    if (atoi(numsims.c_str()) >= 2)
        force_msim = true;

    if (!force_msim && (carrier == "retgb" || carrier == "reteu" || carrier == "retde" || carrier == "vfau")) {
        // These are single SIM XT1562 devices
        single_sim();
        property_set("ro.product.device", "lux");
        property_set("ro.build.description", "lux_reteu-user 5.1.1 LPD23.118-10 15 release-keys");
        property_set("ro.build.fingerprint", "motorola/lux_reteu/lux:5.1.1/LPD23.118-10/15:user/release-keys");
        property_set("ro.build.product", "lux");
        property_set("ro.mot.build.customerid", "reteu");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("persist.radio.mot_ecc_custid", "emea");
        property_set("persist.radio.mot_ecc_enabled", "1");
        property_set("persist.radio.process_sups_ind", "0");
    }
    else if (sku == "XT1562" || radio == "0x4") {
        dual_sim();
        property_set("ro.product.device", "lux_uds");
        property_set("ro.build.description", "lux_retasia_ds-user 5.1.1 LPD23.118-10 14 release-keys");
        property_set("ro.build.fingerprint", "motorola/lux_retasia_ds/lux_uds:5.1.1/LPD23.118-10/14:user/release-keys");
        property_set("ro.build.product", "lux_uds");
        property_set("ro.mot.build.customerid", "retasiaall");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("persist.radio.mot_ecc_custid", "emea");
        property_set("persist.radio.mot_ecc_enabled", "1");
        property_set("persist.radio.process_sups_ind", "0");
    }
    else if (force_msim || carrier == "retbr" || carrier == "retla" || carrier == "tefbr" ||
             carrier == "timbr" || carrier == "retmx") {
        // These are dual SIM XT1563 devices
        dual_sim();
        property_set("ro.product.device", "lux_uds");
        property_set("ro.build.description", "lux_retla_ds-user 5.1.1 LPD23.118-6.1 2 release-keys");
        property_set("ro.build.fingerprint", "motorola/lux_retla_ds/lux_uds:5.1.1/LPD23.118-6.1/2:user/release-keys");
        property_set("ro.build.product", "lux_uds");
        property_set("ro.mot.build.customerid", "retla");
        property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
        property_set("persist.radio.mot_ecc_enabled", "1");
        property_set("persist.radio.process_sups_ind", "1");
    }
    else if (sku == "XT1563" || radio == "0x8") {
        single_sim();
        property_set("ro.product.device", "lux");
        property_set("ro.build.description", "lux_retca-user 5.1.1 LPD23.118-10 19 release-keys");
        property_set("ro.build.fingerprint", "motorola/lux_retca/lux:5.1.1/LPD23.118-10/19:user/release-keys");
        property_set("ro.build.product", "lux");
        property_set("ro.mot.build.customerid", "retca");
        property_set("ro.gsm.data_retry_config", "");
        property_set("persist.radio.mot_ecc_enabled", "");
        property_set("persist.radio.process_sups_ind", "1");
    }
}

static void dual_sim(void)
{
    property_set("persist.radio.force_get_pref", "1");
    property_set("persist.radio.multisim.config", "dsds");
    property_set("persist.radio.plmn_name_cmp", "1");
    property_set("ro.telephony.ril.config", "simactivation");
}

static void single_sim(void)
{
    property_set("persist.radio.force_get_pref", "");
    property_set("persist.radio.multisim.config", "");
    property_set("persist.radio.plmn_name_cmp", "");
    property_set("ro.telephony.ril.config", "");
}
