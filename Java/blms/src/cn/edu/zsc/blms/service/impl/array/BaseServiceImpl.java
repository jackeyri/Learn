package cn.edu.zsc.blms.service.impl.array;

import cn.edu.zsc.blms.App;
import cn.edu.zsc.blms.domain.BaseEntity;
import cn.edu.zsc.blms.exception.EntityNotExistException;

public abstract class BaseServiceImpl {

    protected final BaseEntity[] DATA;
    protected int idCounter;

    public BaseServiceImpl() {
        DATA = new BaseEntity[100];
    }

    /**
     * 接收用户输入的ID值，并根据ID值返回实体对象。如果有异常情况，则抛出EntityNotExistException
     */
    protected BaseEntity getOne() throws EntityNotExistException {
        BaseEntity entity;
        try {
            int id = Integer.parseInt(App.input.nextLine());
            if (id >= idCounter || DATA[id] == null) {
                throw new EntityNotExistException();
            }
            entity = DATA[id];
        } catch (NumberFormatException e) {
            throw new EntityNotExistException("ID为整数，请输入整数值");
        }
        return entity;
    }
}
