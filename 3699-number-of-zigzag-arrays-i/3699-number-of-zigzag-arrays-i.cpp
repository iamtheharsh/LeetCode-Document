class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        ll ans = 0;
        // memset(dp,-1,sizeof(dp));
        // for(int i=l;i<=r;i++){
        //     ans = (ans + solve(1,i,false,false))%mod;
        // }
        ll nxt[2001][2][2];
        ll cur[2001][2][2];
        memset(nxt,0,sizeof(nxt));
        memset(cur,0,sizeof(cur));

        for(int prev=1;prev<=2000;prev++){
            for(int inc=0;inc<2;inc++){
                for(int dec=0;dec<2;dec++){
                    nxt[prev][inc][dec] = 1;
                }
            }
        }

        for(int i=n-1;i>=1;i--){
            vector<ll> pinc(2001),pdec(2001);
            pinc[0] = nxt[0][0][1];
            pdec[0] = nxt[0][1][0];
            for(int x=1;x<=2000;x++){
                pinc[x] = (pinc[x-1] + nxt[x][0][1])%mod;
                pdec[x] = (pdec[x-1] + nxt[x][1][0])%mod;
            }

            for(int prev = l;prev<=r;prev++){
                for(int inc=0;inc<2;inc++){
                    for(int dec=0;dec<2;dec++){
                        if(inc && dec) continue;
                        ll temp = 0;
                        if(inc){
                            // for(int num=l;num<prev;num++){
                            //     temp = temp + dp[i+1][num][0][1];
                            //     temp = temp%mod;
                            // }
                            temp = (pinc[prev-1] - pinc[l-1] + mod) % mod;
                        }
                        else if(dec){
                            // for(int num=prev+1;num<=r;num++){
                            //     temp = temp + dp[i+1][num][1][0];
                            //     temp = temp%mod;
                            // }
                            temp = (pdec[r] - pdec[prev] + mod) % mod;
                        }
                        else {
                            // for(int num=l;num<prev;num++){
                            //     temp = temp + dp[i+1][num][0][1];
                            //     temp = temp%mod;
                            // }
                            // for(int num=prev+1;num<=r;num++){
                            //     temp = temp + dp[i+1][num][1][0];
                            //     temp = temp%mod;
                            // }
                            temp = (pinc[prev-1] - pinc[l-1] + mod) % mod;
                            temp = (temp + pdec[r] - pdec[prev] + mod) % mod;
                        }

                        cur[prev][inc][dec] = temp;
                    }
                }
            }

            for(int prev = 1; prev <= 2000; prev++){
                for(int inc = 0; inc < 2; inc++){
                    for(int dec = 0; dec < 2; dec++){
                        nxt[prev][inc][dec] = cur[prev][inc][dec];
                        cur[prev][inc][dec] = 0;
                    }
                }
            }
        }

        for(int i=l;i<=r;i++){
            ans = (ans + nxt[i][0][0])%mod;
        }

        return ans;
    }
};
