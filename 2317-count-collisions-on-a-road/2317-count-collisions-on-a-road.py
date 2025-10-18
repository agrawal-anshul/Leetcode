class Solution:
    def countCollisions(self, directions: str) -> int:
        s = directions

        # Count cars that are not already standing
        moving = sum(1 for c in s if c != 'S')

        # Skip leading L's — they never hit anyone (they move left off the road)
        i = 0
        n = len(s)
        while i < n and s[i] == 'L':
            i += 1

        # Skip trailing R's — they never hit anyone (they move right off the road)
        j = n - 1
        while j >= 0 and s[j] == 'R':
            j -= 1

        # moving cars minus safe ones on both ends = collisions
        return max(0, moving - (i + (n - 1 - j)))