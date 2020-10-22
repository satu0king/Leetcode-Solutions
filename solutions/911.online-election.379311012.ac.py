class TopVotedCandidate(object):
    def __init__(self, persons, times):
        self.A = []
        count = collections.Counter()
        leader, m = None, 0  # leader, num votes for leader

        for p, t in zip(persons, times):
            count[p] += 1
            c = count[p]
            if c >= m:
                if p != leader:  # lead change
                    leader = p
                    self.A.append((t, leader))

                m = c

    def q(self, t):
        i = bisect.bisect(self.A, (t, float('inf')), 1)
        return self.A[i-1][1]
