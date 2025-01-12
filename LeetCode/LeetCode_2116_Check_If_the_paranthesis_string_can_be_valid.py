def canBeValid( s: str, locked: str) -> bool:
    if len(s) % 2 != 0 : return False 

    open_bracket_count , closed_bracket_count = 0,0
    for para, isLocked in zip(s,locked) :
        if para == '(' or isLocked == "0" :
            open_bracket_count += 1
        else : open_bracket_count -= 1

        if open_bracket_count < 0 : return False 
    
    for para, isLocked in zip(reversed(s), reversed(locked)) :
        if para == ')' or isLocked == '0' :
            closed_bracket_count += 1
        else : closed_bracket_count -= 1
        if closed_bracket_count < 0 : return False 
    
    return True


s = input()
locked = input()
print("true" if canBeValid(s, locked) else "false")