




#request 网址，并返回json data
def getHTML(url):
    headers = {
        #这边请输入你自己的浏览器的对应参数，不要照抄，否则不work
        'user-agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Mobile Safari/537.36',
        'cookie': 'dpr=2; ig_did=FDFAFE7B-9440-4F06-8222-0D22BF0793E7; ig_nrcb=1; mid=ZW7eTQAEAAFeLr2A1IN2VGiUKljz; csrftoken=cwZpN9Uo3YkJiEqMHjkSdfqI2EBgquVk; ds_user_id=4354643472; sessionid=4354643472%3ATJxOvWIWX1cw3f%3A8%3AAYeCesIgKaXZBHYlN9EiHPPxc4A9KJJPJlkHvZrh_A; datr=Vd5uZa7tlaCAa_43hQwdeFDR; shbid="9188\0544354643472\0541733300697:01f778fbcaee48f14cbdd35d792c588b8054d14262553ce4bef2835bf9578d448e5f4f3c"; shbts="1701764697\0544354643472\0541733300697:01f7ab66de86375c9c7e3e3793dd261eb3917c6a8c7b9867902ee4c538e66a0cf3e6f2f1"; rur="EAG\0544354643472\0541733301697:01f7f240f11418bc60b707b2b3731485c46c330244dc6fdba8e29275e1e6f23884a17f73"'
    }
    html = requests.get(url,headers=headers)
    data = html.json()
    return data


#获取所有网址list，一个网址里包含12个url图片src
def getURLlist(url,id):
    url_list = [url]
    while url != None or has_next_page_data_info['has_next_page'] == True:
        data = getHTML(url)

        #判断有没有下一个page
        has_next_page_data_info = data['data']['user']['edge_owner_to_timeline_media']['page_info']
        if has_next_page_data_info['has_next_page'] == True:
            #获取下一页所需要的新的after参数
            after_new = has_next_page_data_info['end_cursor'].rstrip('=')
            url = "https://www.instagram.com/graphql/query/?query_hash=02e14f6a7812a876f7d133c9555b1151&variables=%7B%22id%22%3A%22"+id+"%22%2C%22first%22%3A12%2C%22after%22%3A%22" + after_new + "%3D%3D%22%7D"
            url_list.append(url)
        else:
            break

    return url_list


#获取图片list
def getImageURL(data):
    img_data_info = data['data']['user']['edge_owner_to_timeline_media']['edges']
    #print(img_data_info)

    img_url_list = []
    for i in img_data_info:
        img_url = i['node']['display_url']
        img_url_list.append(img_url)
    #print(img_url_list)
    print("共"+str(len(img_url_list))+"张")
    return img_url_list


#访问图片url list内的url，然后下载图片
def scapyImage(img_url_list,id):
    for img_url in img_url_list:
        img_data = requests.get(img_url).content
        img_name = img_url.split('?')[0].split('/')[-1].split('_')[0] + ".jpg"
        file_name = "id=" + id

        #判断文件夹是否存在，不存在便新建一个
        if not os.path.exists(file_name):
            os.mkdir(file_name)
        with open(file_name+"\\" + img_name,"wb") as f:
            print('正在下载：' + img_name)
            f.write(img_data)





if __name__ == "__main__":
    id = input('请输入该个人IG的id参数是（在network的字符参数查看）：')
    after = input('请输入after参数：')

    print("正在准备中，请稍后。。。")

    #目标网址，第一个url
    first_url = 'https://www.instagram.com/colin.anthony2/'
    url_list = getURLlist(first_url,id)

    for url_li in url_list:
        print('==============正在下载第{}页数据：'.format(str(url_list.index(url_li)+1)))
        data = getHTML(url_li)
        img_url_list = getImageURL(data)
        scapyImage(img_url_list,id)