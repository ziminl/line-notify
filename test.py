import requests


def main():
    try:
        api_url = 'https://notify-api.line.me/api/notify'
        token = 'access token'

        response = requests.post(
            api_url,
            headers = {
                'Authorization':'Bearer ' + token
            },
            data = {
                'message' : 'testtesttest'
            }            
        )

    except Exception as ex:
        print(ex)

if __name__ == "__main__":
     main()
