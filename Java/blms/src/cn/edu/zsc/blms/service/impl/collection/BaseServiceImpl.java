package cn.edu.zsc.blms.service.impl.collection;

import cn.edu.zsc.blms.App;
import cn.edu.zsc.blms.domain.BaseEntity;
import cn.edu.zsc.blms.exception.EntityNotExistException;

import java.util.Map;
import java.util.TreeMap;

public abstract class BaseServiceImpl<T extends BaseEntity> {

    protected final Map<Integer, T> DATA;
    protected int idCounter;

    public BaseServiceImpl() {
        DATA = new TreeMap<>();
    }

    /**
     * 接收用户输入的ID值，并根据ID值返回实体对象
     *
     * @return 根据ID值返回实体对象
     * @throws EntityNotExistException 如ID值非法或不存在该ID的对象，则抛出该异常
     */
    protected T getOne() throws EntityNotExistException {
        T entity;
        try {
            int id = Integer.parseInt(App.input.nextLine());
            if (!DATA.containsKey(id)) {
                throw new EntityNotExistException();
            }
            entity = DATA.get(id);
        } catch (NumberFormatException e) {
            throw new EntityNotExistException("ID为整数，请输入整数值");
        }
        return entity;
    }
}
