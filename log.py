import logging
import logging.config
import yaml
import time

with open("./logger.yaml", 'r') as f:
    config = yaml.safe_load(f.read())
    logging.config.dictConfig(config)
    # logging.config.dictConfig(config)

logger = logging.getLogger('logger')

while 1:
    logger.debug('tes')
    time.sleep(2)
    logger.info('tes')
    time.sleep(2)
    logger.warning('tes')
    time.sleep(2)
    logger.error('tes')
    time.sleep(2)
    logger.critical('tes')
    
# logging.basicConfig(level=logging.DEBUG)

# logger1 = logging.getLogger('handler1')
# logger1.setLevel(logging.DEBUG)
# s_handler = logging.StreamHandler()
# s_handler.setLevel(logging.DEBUG)
# s_handler.setFormatter(logging.Formatter('%(levelname)s:%(name)s:%(message)s'))

# logger2 = logging.getLogger('handler2')
# logger2.setLevel(logging.DEBUG)
# s2_handler = logging.StreamHandler()
# s2_handler.setLevel(logging.WARNING)
# s2_handler.setFormatter(logging.Formatter('%(levelname)s:%(name)s:%(message)s'))
# # s_handler.formatter(logging.Formatter())
# logger1.addHandler(s_handler)
# logger2.addHandler(s2_handler)

# # logger.info('test')
# logger1.info('tes1')
# logger2.warning('tes2')
