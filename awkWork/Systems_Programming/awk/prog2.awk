#!/usr/bin/awk

/User-Name/ {
    username = $3
    username = sub(/\"/, "")
    print username
}
