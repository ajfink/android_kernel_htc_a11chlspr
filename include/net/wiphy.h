/*
 * wireless hardware and networking interfaces structures
 * and registration/helper functions
 */

/**
 * enum wiphy_flags - wiphy capability flags
 *
 * @WIPHY_FLAG_CUSTOM_REGULATORY:  tells us the driver for this device
 * 	has its own custom regulatory domain and cannot identify the
 * 	ISO / IEC 3166 alpha2 it belongs to. When this is enabled
 * 	we will disregard the first regulatory hint (when the
 * 	initiator is %REGDOM_SET_BY_CORE).
 * @WIPHY_FLAG_STRICT_REGULATORY: tells us the driver for this device will
 *	ignore regulatory domain settings until it gets its own regulatory
 *	domain via its regulatory_hint() unless the regulatory hint is
 *	from a country IE. After its gets its own regulatory domain it will
 *	only allow further regulatory domain settings to further enhance
 *	compliance. For example if channel 13 and 14 are disabled by this
 *	regulatory domain no user regulatory domain can enable these channels
 *	at a later time. This can be used for devices which do not have
 *	calibration information guaranteed for frequencies or settings
 *	outside of its regulatory domain. If used in combination with
 *	WIPHY_FLAG_CUSTOM_REGULATORY the inspected country IE power settings
 *	will be followed.
 * @WIPHY_FLAG_DISABLE_BEACON_HINTS: enable this if your driver needs to ensure
 *	that passive scan flags and beaconing flags may not be lifted by
 *	cfg80211 due to regulatory beacon hints. For more information on beacon
 *	hints read the documenation for regulatory_hint_found_beacon()
 * @WIPHY_FLAG_NETNS_OK: if not set, do not allow changing the netns of this
 *	wiphy at all
 * @WIPHY_FLAG_ENFORCE_COMBINATIONS: Set this flag to enforce interface
 *	combinations for this device. This flag is used for backward
 *	compatibility only until all drivers advertise combinations and
 *	they will always be enforced.
 * @WIPHY_FLAG_PS_ON_BY_DEFAULT: if set to true, powersave will be enabled
 *	by default -- this flag will be set depending on the kernel's default
 *	on wiphy_new(), but can be changed by the driver if it has a good
 *	reason to override the default
 * @WIPHY_FLAG_4ADDR_AP: supports 4addr mode even on AP (with a single station
 *	on a VLAN interface)
 * @WIPHY_FLAG_4ADDR_STATION: supports 4addr mode even as a station
 * @WIPHY_FLAG_CONTROL_PORT_PROTOCOL: This device supports setting the
 *	control port protocol ethertype. The device also honours the
 *	control_port_no_encrypt flag.
 * @WIPHY_FLAG_IBSS_RSN: The device supports IBSS RSN.
 * @WIPHY_FLAG_MESH_AUTH: The device supports mesh authentication by routing
 *	auth frames to userspace. See @NL80211_MESH_SETUP_USERSPACE_AUTH.
 * @WIPHY_FLAG_SUPPORTS_SCHED_SCAN: The device supports scheduled scans.
 * @WIPHY_FLAG_SUPPORTS_FW_ROAM: The device supports roaming feature in the
 *	firmware.
 * @WIPHY_FLAG_AP_UAPSD: The device supports uapsd on AP.
 * @WIPHY_FLAG_SUPPORTS_TDLS: The device supports TDLS (802.11z) operation.
 * @WIPHY_FLAG_TDLS_EXTERNAL_SETUP: The device does not handle TDLS (802.11z)
 *	link setup/discovery operations internally. Setup, discovery and
 *	teardown packets should be sent through the @NL80211_CMD_TDLS_MGMT
 *	command. When this flag is not set, @NL80211_CMD_TDLS_OPER should be
 *	used for asking the driver/firmware to perform a TDLS operation.
 * @WIPHY_FLAG_HAVE_AP_SME: device integrates AP SME
 * @WIPHY_FLAG_REPORTS_OBSS: the device will report beacons from other BSSes
 *	when there are virtual interfaces in AP mode by calling
 *	cfg80211_report_obss_beacon().
 * @WIPHY_FLAG_AP_PROBE_RESP_OFFLOAD: When operating as an AP, the device
 *	responds to probe-requests in hardware.
 * @WIPHY_FLAG_OFFCHAN_TX: Device supports direct off-channel TX.
 * @WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL: Device supports remain-on-channel call.
 * @WIPHY_FLAG_DISABLE_11D_HINT_FROM_CORE: enable this flag if the driver
 *	does not want the channel flags to be changed by the country IE of the
 *	connected BSS due to a regulatory hint from the core
 */
enum wiphy_flags {
	WIPHY_FLAG_CUSTOM_REGULATORY		= BIT(0),
	WIPHY_FLAG_STRICT_REGULATORY		= BIT(1),
	WIPHY_FLAG_DISABLE_BEACON_HINTS		= BIT(2),
	WIPHY_FLAG_NETNS_OK			= BIT(3),
	WIPHY_FLAG_PS_ON_BY_DEFAULT		= BIT(4),
	WIPHY_FLAG_4ADDR_AP			= BIT(5),
	WIPHY_FLAG_4ADDR_STATION		= BIT(6),
	WIPHY_FLAG_CONTROL_PORT_PROTOCOL	= BIT(7),
	WIPHY_FLAG_IBSS_RSN			= BIT(8),
	WIPHY_FLAG_MESH_AUTH			= BIT(10),
	WIPHY_FLAG_SUPPORTS_SCHED_SCAN		= BIT(11),
	WIPHY_FLAG_ENFORCE_COMBINATIONS		= BIT(12),
	WIPHY_FLAG_SUPPORTS_FW_ROAM		= BIT(13),
	WIPHY_FLAG_AP_UAPSD			= BIT(14),
	WIPHY_FLAG_SUPPORTS_TDLS		= BIT(15),
	WIPHY_FLAG_TDLS_EXTERNAL_SETUP		= BIT(16),
	WIPHY_FLAG_HAVE_AP_SME			= BIT(17),
	WIPHY_FLAG_REPORTS_OBSS			= BIT(18),
	WIPHY_FLAG_AP_PROBE_RESP_OFFLOAD	= BIT(19),
	WIPHY_FLAG_OFFCHAN_TX			= BIT(20),
	WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL	= BIT(21),
	WIPHY_FLAG_DISABLE_11D_HINT_FROM_CORE	= BIT(22),
};
