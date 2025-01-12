def isValid( s: str) -> bool:
    para_hash = {
        '(' : ')',
        '{' : '}',
        '[' : ']'
    }
    track = ""
    for ch in s :
        if len(track) == 0 :
            track += ch
            continue
        last_ch = track[len(track)-1]
        if last_ch in para_hash.keys() and para_hash[last_ch] == ch:
            track = track[:len(track)-1]
            continue
        track += ch
    return False if len(track) > 0 else True
        
para = input()
print("true" if isValid(para) else "false")