import requests
@service
def Front_Doorbell_Chime():
        log.info(f"Front Doorbell: from id {id}")
        res=task.executor(requests.post,'http://192.168.0.7/Front')
@service
def Rear_Doorbell_Chime():
        log.info(f"Rear Doorbell: from id {id}")
        res=task.executor(requests.post,'http://192.168.0.7/Rear')
