!/bin/bash

##############################################################################
#
# Module: common-init.sh
#
# Function:
#	This script must be sourced; it sets variables used by other
#	scripts in this directory.
#
# Usage:
#	source ci/lmic-filter.sh
#
# Copyright and License:
#	See accompanying LICENSE.md file
#
# Author:
#	Terry Moore, MCCI	February 2021
#
##############################################################################

#### Capture the file path ####
MCCI_THISFILE="$0"

#### mandatory function: do the filtering
function _lmic_filter {
	declare -r CMD="$1"
	shift
	case "$CMD" in
	# return 0 (success) if should skip this sketch.
	"process")
		return 0
		;;
	"use-progcfg")
		if [[ "$MCCI_CI_ARCH" = "avr" && "$(basename "$1")" = "compliance-otaa-halconfig.ino" ]]; then
			echo 0
		else
			echo 1
		fi
		;;
	"projcfg")
		declare -r LMIC_FILTER_SKETCH="$1"
		_debug _lmic_filter: LMIC_FILTER_SKETCH="$LMIC_FILTER_SKETCH"
		shift
		if [[ "$MCCI_CI_ARCH" = "avr" && "$(basename "$LMIC_FILTER_SKETCH")" = "compliance-otaa-halconfig.ino" ]]; then
			_projcfg_class_a "$@"
		else
			_projcfg "$@"
		fi
		;;
	*)
		_error "_lmic_filter: unknown command:" "$@"
		;;
	esac
	return 1
}
