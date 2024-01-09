import requests

url = 'https://www.instagram.com/colin.anthony2/'

headers = {
    'user-agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Mobile Safari/537.36',
    'cookie': 'uuid_tt_dd=10_19181550270-1701587241605-253106; c_adb=1; loginbox_strategy=%7B%22taskId%22%3A308%2C%22abCheckTime%22%3A1701587243214%2C%22version%22%3A%22exp1%22%2C%22blog-threeH-dialogtipShowTimes%22%3A1%7D; UserName=qq_36433853; UserInfo=3a60012f0e49430aa44ce1de623a7126; UserToken=3a60012f0e49430aa44ce1de623a7126; UserNick=%E6%88%91%E5%B0%B1%E4%BD%8F%E5%9C%A8%E9%95%BF%E6%B1%9F%E5%B0%BE; AU=3D7; UN=qq_36433853; BT=1701587280025; p_uid=U010000; Hm_up_6bcd52f51e9b3dce32bec4a3997715ac=%7B%22islogin%22%3A%7B%22value%22%3A%221%22%2C%22scope%22%3A1%7D%2C%22isonline%22%3A%7B%22value%22%3A%221%22%2C%22scope%22%3A1%7D%2C%22isvip%22%3A%7B%22value%22%3A%220%22%2C%22scope%22%3A1%7D%2C%22uid_%22%3A%7B%22value%22%3A%22qq_36433853%22%2C%22scope%22%3A1%7D%7D; log_Id_click=13; c_segment=2; dc_sid=909c77e3a01fe2db6a70ddf64a6e0a71; firstDie=1; Hm_lvt_6bcd52f51e9b3dce32bec4a3997715ac=1701587243,1701757133; dc_session_id=10_1701765190757.309830; c_pref=https%3A//cn.bing.com/; c_ref=https%3A//www.bing.com/; c_first_ref=www.bing.com; c_first_page=https%3A//blog.csdn.net/Inochigohan/article/details/120636769; creative_btn_mp=3; c_dsid=11_1701766053259.031117; c_page_id=default; dc_tos=s56r39; log_Id_pv=17; Hm_lpvt_6bcd52f51e9b3dce32bec4a3997715ac=1701766056; log_Id_view=627'
}

def get_urls(url):
    try:
        response = requests.get(url, headers=headers,timeout=50)
        if response.status_code == 200:
            return response.text
        else:
            print('请求错误状态码：', response.status_code)
    except Exception as e:
        print(e)
        return None
html = get_urls(url)
print(html)