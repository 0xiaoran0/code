# url = "https://k0u2aye7y8ey10z.djvod.ndcimgs.com/upic/2025/05/17/15/BMjAyNTA1MTcxNTUxMTZfNjgyMDE1NzY1XzE2NDQ4MDU4ODc1OV8xXzM=_b_B92bb7e6c5d34bff2567f2639f8e58c24.mp4?tag=1-1754053205-unknown-0-boshew0jwl-9542cc564dc436ee&provider=self&clientCacheKey=3x6mcugw6ztu6we_b.mp4&di=b672e667&bp=10004&x-ks-ptid=164480588759&kwai-not-alloc=self-cdn&kcdntag=p:Henan;i:ChinaUnicom;ft:UNKNOWN;h:COLD;pn:kuaishouVideoProjection&ocid=100001003&tt=b&ss=vpm"
#
# import requests
#
# res = requests.get(url)
#
# open("视频.mp4","wb").write(res.content)






# import requests
#
# url = "https://xy111x6x164x11xy.mcdn.bilivideo.cn:4483/upgcxcode/51/48/30560224851/30560224851_da1-1-100022.m4s?e=ig8euxZM2rNcNbdlhoNvNC8BqJIzNbfqXBvEqxTEto8BTrNvN0GvT90W5JZMkX_YN0MvXg8gNEV4NC8xNEV4N03eN0B5tZlqNxTEto8BTrNvNeZVuJ10Kj_g2UB02J0mN0B5tZlqNCNEto8BTrNvNC7MTX502C8f2jmMQJ6mqF2fka1mqx6gqj0eN0B599M=&uipk=5&os=mcdn&og=hw&mid=0&gen=playurlv3&deadline=1754120196&nbs=1&platform=pc&trid=00007a2fc3be3dcb43069dcea55f19a84cdu&oi=3060983399&upsig=93817e1b9aab2b386095ff881e524e54&uparams=e,uipk,os,og,mid,gen,deadline,nbs,platform,trid,oi&mcdnid=50035939&bvc=vod&nettype=0&bw=156328&lrs=71&dl=0&f=u_0_0&agrr=0&buvid=99528198-42FA-80DB-C570-899CA6B9297D25363infoc&build=0&orderid=0,3&codecexp1=14528.86.0"
#
# headers = {"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/138.0.0.0 Safari/537.36 Edg/138.0.0.0","referer":"https://www.bilibili.com/video/BV1bkNjz4E3f/?spm_id_from=333.1007.tianma.1-1-1.click"}
#
# res = requests.get(url, headers=headers)
#
# open("视频1.mp4","wb").write(res.content)
#
# url = "https://xy183x204x32x111xy.mcdn.bilivideo.cn:4483/upgcxcode/51/48/30560224851/30560224851_da1-1-30216.m4s?e=ig8euxZM2rNcNbdlhoNvNC8BqJIzNbfqXBvEqxTEto8BTrNvN0GvT90W5JZMkX_YN0MvXg8gNEV4NC8xNEV4N03eN0B5tZlqNxTEto8BTrNvNeZVuJ10Kj_g2UB02J0mN0B5tZlqNCNEto8BTrNvNC7MTX502C8f2jmMQJ6mqF2fka1mqx6gqj0eN0B599M=&uipk=5&gen=playurlv3&os=mcdn&trid=00007a2fc3be3dcb43069dcea55f19a84cdu&mid=0&deadline=1754120196&nbs=1&platform=pc&og=cos&oi=3060983399&upsig=76acc5cd90f8705b224164bddae1e055&uparams=e,uipk,gen,os,trid,mid,deadline,nbs,platform,og,oi&mcdnid=50033786&bvc=vod&nettype=0&bw=52040&lrs=71&buvid=99528198-42FA-80DB-C570-899CA6B9297D25363infoc&build=0&dl=0&f=u_0_0&agrr=0&orderid=0,3&codecexp1=14528.86.0"
#
# headers = {"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/138.0.0.0 Safari/537.36 Edg/138.0.0.0","referer":"https://www.bilibili.com/video/BV1mzfMYsEm1/?spm_id_from=333.788.recommend_more_video.1"}
#
# res = requests.get(url, headers=headers)
#
# open("视频1.mp3","wb").write(res.content)
#
# from moviepy.editor import *
#
# a = VideoFileClip("视频1.mp4")
#
# b = AudioFileClip("视频1.mp3")
#
# final = a.set_audio(b)
#
# final.write_videofile("视频1真.mp4")



