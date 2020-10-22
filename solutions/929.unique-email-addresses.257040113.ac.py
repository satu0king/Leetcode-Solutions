class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        def f(email):
            (localname, domain) = email.split('@')
            localname = localname.split('+')[0]
            localname = localname.replace('.','')
            return localname + "@" + domain
        
        return len(set(map(f, emails)))
